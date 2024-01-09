#include <bits/stdc++.h>
using namespace std;
int n,q;
long long int a[200010];
long long int BIT[300010];
void push(int x,int v){
    while(x<300010){
        BIT[x]+=v;
        x+=x&(-x);
    }
    return;
}
long long int query(int x){
    long long int tmp=0;
    while(x>0){
        tmp+=BIT[x];
        x-=x&(-x);
    }
    return tmp;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int A;
        cin>>A;
        if(A==2){
            int B;
            cin>>B;
            cout<<query(B)+a[B]<<'\n';
        }else if(A==1){
            int B,C,D;
            cin>>B>>C>>D;
            push(B,D);
            push(C+1,-D);
        }
    }
    return 0;
}