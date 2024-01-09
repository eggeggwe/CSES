#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,long long int> > graph;
long long int dis[2510];
vector<int> Graph[2510];
vector<int> bgraph[2510];
bitset<2510> go,back;
void dfs(int a){
    go[a]=1;
    for(int i=0;i<Graph[a].size();i++){
        if(!go[Graph[a][i]]){
            dfs(Graph[a][i]);
        }
    }
    return;
}
void dfs2(int a){
    back[a]=1;
    for(int i=0;i<bgraph[a].size();i++){
        if(!back[bgraph[a][i]]){
            dfs2(bgraph[a][i]);
        }
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    go.reset();
    back.reset();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        graph.push_back(tie(a,b,c));
        Graph[a].push_back(b);
        bgraph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        dis[i]=-1e16;
    }
    dfs(1);
    dfs2(n);
    dis[1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<graph.size();j++){
            int a,b;
            long long int c;
            tie(a,b,c)=graph[j];
            dis[b]=max(dis[b],dis[a]+c);
        }
    }
    bool door=true;
    for(int i=0;i<graph.size();i++){
        int a,b;
        long long int c;
        tie(a,b,c)=graph[i];
        if(dis[b]<dis[a]+c){
            if(go[b] && back[b]){
                door=false;
            }
        }
    }
    if(door){
        cout<<dis[n];
    }else{
        cout<<-1;
    }
    return 0;
}