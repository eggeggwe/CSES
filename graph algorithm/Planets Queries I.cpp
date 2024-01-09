#include <bits/stdc++.h>
using namespace std;
int boss[40][200010];
void jump(int a,int b){
    for(int i=30,j=(1<<30);i>=0;i--,j>>=1){
        if(b&j){
            a=boss[i][a];
        }
    }
    cout<<a<<'\n';
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>boss[0][i];
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            boss[i][j]=boss[i-1][boss[i-1][j]];
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        jump(a,b);
    }
    return 0;
}