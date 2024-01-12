#include <bits/stdc++.h>
using namespace std;
long long int graph[30][30];
long long int dp[30][2000010];
long long int p[30];
const long long int MOD=1e9+7;
vector<int> v[30];
vector<int> vv[2000010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[--a][--b]++;
    }
    p[0]=1;
    for(int i=1;i<=20;i++){
        p[i]=p[i-1]*2;
    }
    dp[0][1]=1;
    for(int i=1;i<p[n];i++){
        for(int j=0;j<n;j++){
            if(i&p[j])vv[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(i!=j && graph[j][i]){
                for(int u=0;u<graph[j][i];u++)v[i].push_back(j);
            }
        }
    }
    for(int i=1;i<p[n];i++){
        for(auto tmp:vv[i]){
            int o=i^p[tmp];
            for(auto tmp2:v[tmp]){
                dp[tmp][i]+=dp[tmp2][o];
            }
            dp[tmp][i]%=MOD;
        }
    }
    printf("%lld",dp[n-1][p[n]-1]);
    return 0;
}