#include <bits/stdc++.h>
using namespace std;
long long int dp[510][510];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=1e8;
            if(i==j){
                dp[i][j]=0;
            }else{
                for(int k=1;k*k<=i;k++){
                    if(i%k==0){
                        if(j-k>=0)dp[i][j]=min(dp[i][j],dp[i][j-k]+i/k);
                    }
                }
                for(int k=1;k*k<=j;k++){
                    if(j%k==0){
                        if(i-k>=0)dp[i][j]=min(dp[i][j],dp[i-k][j]+j/k);
                    }
                }
                
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j)cerr<<" ";
            cerr<<dp[i][j];
        }
        cerr<<endl;
    }
    cout<<dp[n][m];
    return 0;
}