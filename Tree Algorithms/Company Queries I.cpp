#include <bits/stdc++.h>
using namespace std;
int boss[25][200010];
void jump(int a,int b){
    for(int i=0;i<20;i++){
        if(b&(1<<i)){
            a=boss[i][a];
        }
        if(a==0){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<a<<'\n';
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    boss[0][1]=0;
    for(int i=2;i<=n;i++){
        cin>>boss[0][i];
    }
    for(int i=1;i<=20;i++){
        boss[i][1]=0;
        for(int j=2;j<=n;j++){
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