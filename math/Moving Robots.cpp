#include <bits/stdc++.h>
using namespace std;
double dp[110][8][8];
pair<int,int> use[4]={{1,0},{-1,0},{0,1},{0,-1}};
double ans[8][8];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int k;
    cin>>k;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ans[i][j]=1;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            memset(dp,0,sizeof(dp));
            dp[0][i][j]=1;
            for(int K=0;K<k;K++){
                for(int i1=0;i1<8;i1++){
                    for(int j1=0;j1<8;j1++){
                        double dir=0;
                        for(int u=0;u<4;u++){
                            if(i1+use[u].first<0 || i1+use[u].first>=8 || j1+use[u].second<0 || j1+use[u].second>=8)continue;
                            dir++;
                        }
                        for(int u=0;u<4;u++){
                            if(i1+use[u].first<0 || i1+use[u].first>=8 || j1+use[u].second<0 || j1+use[u].second>=8)continue;
                            int i2=i1+use[u].first;
                            int j2=j1+use[u].second;
                            dp[K+1][i2][j2]+=dp[K][i1][j1]/dir;
                        }
                    }
                }
            }
            for(int i1=0;i1<8;i1++){
                for(int j1=0;j1<8;j1++){
                    ans[i1][j1]*=(1-dp[k][i1][j1]);
                }
            }
        }
    }
    double sum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            sum+=ans[i][j];
        }
    }
    sum*=1000000;
    cout<<setprecision(6)<<fixed<<rint(sum)/1000000;
    return 0;
}