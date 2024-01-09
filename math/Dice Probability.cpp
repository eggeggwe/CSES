#include <bits/stdc++.h>
using namespace std;
double dp[610][110];//sum,number of dice
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=6;i++){
        dp[i][1]=(double)1/6;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6*n;j++){
            double sum=0;
            for(int k=1;k<=6;k++){
                if(j-k<0)break;
                sum+=dp[j-k][i-1];
            }
            dp[j][i]=sum/(double)6;
        }
    }
    double sum=0;
    for(int i=a;i<=b;i++){
        double tmp=dp[i][n];
        sum+=tmp;
    }

    sum*=1000000;
    cout<<setprecision(6)<<fixed<<(sum)/1000000;
    return 0;
}