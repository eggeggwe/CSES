#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ans=0;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            ans|=(t!=1 && t%2==1);
        }
        if(ans){
            cout<<"first\n";
        }else{
            cout<<"second\n";
        }
    }
    return 0;
}