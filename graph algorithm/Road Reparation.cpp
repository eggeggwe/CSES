#include <bits/stdc++.h>
using namespace std;
priority_queue<tuple<long long int,int,int>,vector<tuple<long long int,int,int> >,greater<tuple<long long int,int,int> > > pq;
int boss[100010];
int find_boss(int a){
    if(boss[a]==a)return a;
    boss[a]=find_boss(boss[a]);
    return boss[a];
}
void union_node(int a,int b){
    int A=find_boss(a),B=find_boss(b);
    boss[A]=B;
    find_boss(a);
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        pq.push(make_tuple(c,a,b));
    }
    for(int i=0;i<=n;i++){
        boss[i]=i;
    }
    long long int answer=0;
    while(!pq.empty() && n>1){
        long long int c;
        int a,b;
        tie(c,a,b)=pq.top();
        pq.pop();
        if(find_boss(a)!=find_boss(b)){
            union_node(a,b);
            answer+=c;
            n--;
        }
    }
    if(n==1){
        cout<<answer;
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}