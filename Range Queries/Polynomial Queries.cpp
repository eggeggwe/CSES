#include <bits/stdc++.h>
using namespace std;
struct Node{
    long long int sum;
    long long int l=0,r=0;
};
int a[200010];
Node tree[800010];
void build(int l,int r,int id){
    if(l==r){
        tree[id].sum=a[r];
        return;
    }
    int m=(r+l)/2;
    build(l,m,id*2);
    build(m+1,r,id*2+1);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    return;
}
void push(int id){
    tree[id].sum+=(tree[id].l+tree[id].r)*(tree[id].r-tree[id].l+1)/2;
    int m=(tree[id].l+tree[id].r)/2;
    tree[id*2].l=tree[id].l;
    tree[id*2].r=m;
    tree[id*2+1].l=m+1;
    tree[id*2+1].r=tree[id].r;
    tree[id].l=0;
    tree[id].r=0;
    return;
}
int query(int l,int r,int ql,int qr,int id){
    if(ql>r || qr<l)return 0;
    if(ql<=l && qr>=r){
        return tree[id].sum+(tree[id].l+tree[id].r)*(tree[id].r-tree[id].l+1)/2;
    }
    int m=(r+l)/2;
    return query(l,m,ql,qr,id*2)+query(m+1,r,ql,qr,id*2+1);
}
void update(int l,int r,int ql,int qr,int L,int R,int id){
    //cerr<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<L<<" "<<R<<" "<<id<<endl;
    if(l>qr || r<ql)return;
    if(ql<=l && qr>=r){
        push(id);
        tree[id].l=L;
        tree[id].r=R;
        return;
    }
    int m=(l+r)/2;
    int M=(L+R)/2;
    update(l,m,ql,qr,L,M,id*2);
    update(m+1,r,ql,qr,M+1,R,id*2+1);
    tree[id].sum=tree[id*2].sum+(tree[id*2].l+tree[id*2].r)*(tree[id*2].l-tree[id*2].r+1)/2;
    tree[id].sum+=tree[id*2+1].sum+(tree[id*2+1].l+tree[id*2+1].r)*(tree[id*2+1].l-tree[id*2+1].r+1)/2;
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(q--){
        int A,B,C;
        cin>>A>>B>>C;
        if(A==2){
            cout<<query(1,n,B,C,1)<<endl;
        }else{
            update(1,n,B,C,1,C-B+1,1);
        }
    }
    return 0;
}