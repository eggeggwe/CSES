#include <bits/stdc++.h>
using namespace std;
long long int dp[5010][4];//A take pre,A take back,B take pre,B take back
pair<int,int> take[5010][4];
long long int a[5010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<4;i++){
        take[0][i].first=0;
        take[0][i].second=n-1;
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            int test=1;
            //1:
            int Max=dp[i-1][3]+a[take[i-1][3].first];
        }
    }
    return 0;
}