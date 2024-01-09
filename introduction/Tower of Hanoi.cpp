#include <bits/stdc++.h>
using namespace std;
void honai(int a,int b,int c,int deep){
    if(deep==1){
        cout<<a<<" "<<b<<'\n';
    }else{
        honai(a,c,b,deep-1);
        cout<<a<<" "<<b<<'\n';
        honai(c,b,a,deep-1);
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';
    honai(1,3,2,n);
    return 0;
}