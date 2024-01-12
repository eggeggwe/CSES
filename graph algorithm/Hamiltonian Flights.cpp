#include <bits/stdc++.h>
using namespace std;
long long int graph[21][21];
long long int dp[21][2000010];
long long int p[21];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a][b]++;
    }
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]<<1;
    }
    dp[0][1]=1;
    for(int i=1;i<p[n-1];i++){
        for(int j=0;j<n;j++){
            if(!(i&p[j]))continue;
            for(int k=0;k<n-1;k++){
                if(!(i&p[k]))continue;
                if(j==k)continue;
                if(graph[k][j]==0)continue;
                if(graph[k][j]==1){
                    dp[j][i]+=dp[k][i^p[j]];
                }else{
                    dp[j][i]+=dp[k][i^p[j]]*graph[k][j];
                }
                
                // for(int u=0;u<graph[k][j];u++){
                //     dp[j][i]+=dp[k][i^p[j]];
                // }
                dp[j][i]%=1000000007;
            }
        }
    }
    long long int answer=0;
    for(int i=0;i<n-1;i++){
        answer+=dp[i][(p[n]-1)^p[n-1]]*graph[i][n-1];
        answer%=1000000007;
    }
    cout<<answer;
    return 0;
}