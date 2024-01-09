#include <bits/stdc++.h>
using namespace std;
long long int sup(int x,int y,int k){
    if(y==0) return 1;
    if(y==1)return x;
    if(y%2==0){
        long long int tmp=sup(x,y/2,k);
        return (tmp*tmp)%k;
    }else{
        return (x*sup(x,y-1,k))%k;
    }
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    b=sup(b,c,1000000006);
    cout<<sup(a,b,1000000007)<<'\n';
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}