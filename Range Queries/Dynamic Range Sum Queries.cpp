#include <bits/stdc++.h>
using namespace std;
int n,q;
long long int tree[800010];
long long int a[200010];
void build(int id,int l,int r){
    if(l==r){
        tree[id]=a[l];
        return;
    }
    long long int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
    return;
}
long long int query(int tl,int tr,int l,int r,int id){
    if(tl>r || tr<l) return 0;
    if(tl<=l && tr>=r)return tree[id];
    int mid=(l+r)/2;
    return query(tl,tr,l,mid,id*2)+query(tl,tr,mid+1,r,id*2+1);
}
void update(int l,int r,int id,int value,int p){
    if(p<l || p>r)return;
    if(l==r){
        if(l==p)tree[id]=value;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,id*2,value,p);
    update(mid+1,r,id*2+1,value,p);
    tree[id]=tree[id*2]+tree[id*2+1];
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int A,B,C;
        cin>>A>>B>>C;
        if(A==1){
            update(1,n,1,C,B);
        }else if(A==2){
            cout<<query(B,C,1,n,1)<<'\n';
        }
    }
    return 0;
}