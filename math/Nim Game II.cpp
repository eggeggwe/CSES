#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    long long int tmp=0;
    for(int i=0;i<n;i++){
        long long int tmp2;
        cin>>tmp2;
        tmp^=tmp2%4;
    }
    if(tmp==0){
        cout<<"second\n";
    }else{
        cout<<"first\n";
    }
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