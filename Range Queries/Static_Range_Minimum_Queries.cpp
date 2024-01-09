#include <bits/stdc++.h>
using namespace std;
#define Top (int)(log(200010)/log(2))+1;
int a[200010];
int dp[200010][18];
int lg[200010];

int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=a[i];
    }
    for(int i=1;i<=lg[n];i++){
        for(int j=1;j+(1<<i)<=n+1;j++){
            dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=0;i<q;i++){
        int A,B;
        cin>>A>>B;
        cout<<min(dp[A][lg[B-A+1]-1],dp[B-(1<<(lg[B-A+1]-1))+1][lg[B-A+1]-1])<<endl;
    }
    return 0;
}