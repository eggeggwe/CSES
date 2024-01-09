#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    long long int nim=0;
    for(int i=0;i<n;i++){
        long long int tmp;
        cin>>tmp;
        if(i%2)nim^=tmp;
    }
    if(nim==0){
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