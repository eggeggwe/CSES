#include <bits/stdc++.h>
using namespace std;
int n,m;
int dsu[100010];
int find_root(int x){
    if(dsu[x]==x) return x;
    dsu[x]=find_root(dsu[x]);
    return dsu[x];
}
void join(int x,int y){
    int a=find_root(x),b=find_root(y);
    dsu[a]=b;
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dsu[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        join(a,b);
    }
    vector<pair<int,int> >answers;
    int answer=0;
    for(int i=1;i<n;i++){
        if(find_root(i)!=find_root(i+1)){
            answer++;
            answers.push_back(make_pair(i,i+1));
            join(i,i+1);
        }
    }
    cout<<answer<<endl;
    for(int i=0;i<answer;i++){
        cout<<answers[i].first<<" "<<answers[i].second<<'\n';
    }
    return 0;
}