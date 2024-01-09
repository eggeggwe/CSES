#include <bits/stdc++.h>
using namespace std;
int jos(int n,int k,int be){
    //n represent people
    //k represent the number of preple should be removed
    //be is the index of begin
    long long int ans;
    if(be+2*k>n){
        ans=jos(n-(n-be)/2,k-(n-be)/2,be);
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    cout<<jos(n,k,0);
    return;
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