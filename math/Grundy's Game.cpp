#include <bits/stdc++.h>
using namespace std;
long long int dp[1000010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=2000;i++){
        set<int> s;
        for(int j=1;j<(i+1)/2;j++){
            s.insert(dp[j]^dp[(i-j)]);
        }
        auto it=s.begin();
        int tmp=0;
        //cerr<<"i="<<i<<endl;
        while(it!=s.end() && *it==tmp){
            //cerr<<*it<<" ";
            it++;
            tmp++;
        }
        dp[i]=tmp;
        // cerr<<endl;
        // cerr<<dp[i]<<" ";
        // cerr<<endl;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n>=2000){
            cout<<"first\n";
        }else{
            if(dp[n]!=0)cout<<"first\n";
            else cout<<"second\n";
        }
    }
    return 0;
}