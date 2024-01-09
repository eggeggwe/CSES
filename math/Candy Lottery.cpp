#include <bits/stdc++.h>
using namespace std;
double dp[110][110];//n k
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++){
        dp[1][i]=(double)1/k;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            for(int u=1;u<=k;u++){
                dp[i+1][max(j,u)]+=dp[i][j]/(double)k;
            }
        }
    }
    double sum=0;
    for(int i=1;i<=k;i++){
        sum+=dp[n][i]*i;
    }
    sum*=1000000;
    cout<<setprecision(6)<<fixed<<rint(sum)/1000000;
    return 0;
}