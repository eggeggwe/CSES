#include <bits/stdc++.h>
using namespace std;
int n,q;
pair<int,int> a[200010];
vector<pair<int,int> > ID;
map<int,int> record;
priority_queue<int,vector<int>,greater<int> > store[200010];
int tree[800010];
void build(int l,int r,int id){
    if(l==r){
        tree[id]=store[l].top();
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    if(tree[id*2]<tree[id*1+1]){
        tree[id]=tree[id*2];
    }else{
        tree[id]=tree[id*2+1];
    }
    return;
}
int query(int tl,int tr,int l,int r,int id){
    if(tl>r || tr<l)return 1e7;
    if(tl<=l && r<=tr)return tree[id];
    int mid=(l+r)/2;
    return min(query(tl,tr,l,mid,id*2),query(tl,tr,mid+1,r,id*2+1));
}
void update(int p,int l,int r,int id,int value){
    if(p<l || p>r) return;
    if(l==p && p==r){
        tree[id]=value;
        return;
    }
    int mid=(l+r)/2;
    update(p,l,mid,id*2,value);
    update(p,mid+1,r,id*2+1,value);
    if(tree[id*2]<tree[id*1+1]){
        tree[id]=tree[id*2];
    }else{
        tree[id]=tree[id*2+1];
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    int I=2;
    ID.push_back(make_pair(a[1].first,1));
    store[1].push(a[1].second);
    record[a[1].second]=1;
    for(int i=2;i<=n;i++){
        if(ID.back().first!=a[i].first){
            ID.push_back(make_pair(a[i].first,I));
            I++;
        }
        store[I-1].push(a[i].second);
        record[a[i].second]=I-1;
    }
    I--;
    build(1,I,1);
    for(int i=0;i<1;i++){
        int tmp;
        cin>>tmp;
        cout<<query(1,I,1,I,1);
    }
    
    return 0;
}