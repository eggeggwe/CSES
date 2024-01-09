#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
vector<int> graph2[100010];
stack<int> sta;
int comp[100010];
int dsu=1;
bitset<100010> visited;
void dfs(int x){
    visited[x]=1;
    for(int i=0;i<graph[x].size();i++){
        if(visited[graph[x][i]])continue;
        dfs(graph[x][i]);
    }
    sta.push(x);
    return;
}
void dfs2(int x){
    visited[x]=0;
    comp[x]=dsu;
    for(int i=0;i<graph2[x].size();i++){
        if(!visited[graph2[x][i]])continue;
        dfs2(graph2[x][i]);
    }
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph2[b].push_back(a);
    }
    visited.reset();
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i);
    }
    
    while(!sta.empty()){
        if(visited[sta.top()]){
            dfs2(sta.top());
            dsu++;
        }
        sta.pop();
    }
    cout<<dsu-1<<'\n';
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<comp[i];
    }
    return 0;
}