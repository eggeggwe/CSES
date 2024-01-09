#include <bits/stdc++.h>
using namespace std;
int boss[100010][2];
int nums,big=0;
int find_root(int a){
    if(boss[a][0]==a)return a;
    boss[a][0]=find_root(boss[a][0]);
    boss[a][1]=boss[boss[a][0]][1];
    return boss[a][0];
}
void unio(int a,int b){
    int A=find_root(a),B=find_root(b);
    if(A!=B){
        nums--;
        boss[A][1]=boss[A][1]+boss[B][1];
        boss[B][1]=boss[A][1];
    }
    boss[A][0]=B;
    
    big=max(big,boss[B][1]);
    find_root(a);
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    nums=n;
    for(int i=0;i<=n;i++){
        boss[i][0]=i;
        boss[i][1]=1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        unio(a,b);
        cout<<nums<<" "<<big<<'\n';
    }
    return 0;
}