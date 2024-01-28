#include <bits/stdc++.h>
using namespace std;
vector<int> graph[510];
long long int flow[510][510];
vector<pair<int,int> > real_graph[510];
bitset<510> visited;
vector<int> path;
bitset<1010> edge_visited;
int n,m;
long long int dfs(int x,long long int final){
    visited[x]=1;
    if(x==n)return final;
    for(int i=0;i<graph[x].size();i++){
        int next=graph[x][i];
        if(flow[x][next]==0)continue;
        if(visited[next])continue;
        int f=dfs(next,min(final,flow[x][next]));
        if(f>0){
            flow[x][next]-=f;
            flow[next][x]+=f;
            return f;
        }
    }
    return 0;
}
bool dfs2(int x){
    if(x==n){
        path.push_back(n);
        cout<<path.size()<<'\n';
        for(int i=0;i<path.size();i++){
            if(i)cout<<" ";
            cout<<path[i];
        }
        cout<<'\n';
        path.pop_back();
        return true;
    }
    bool door=false;
    
    path.push_back(x);
    for(int i=0;i<real_graph[x].size();i++){
        int id;
        int next;
        tie(next,id)=real_graph[x][i];
        if(flow[x][next]!=0)continue;
        if(edge_visited[id])continue;
        edge_visited[id]=1;
        bool f=dfs2(next);
        if(f){
            //visited[x]=1;
            door=true;
            break;
        }
        edge_visited[id]=0;
    }
    path.pop_back();
    return door;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(flow,0,sizeof(flow));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(flow[a][b]==0 && flow[b][a]==0){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        flow[a][b]=1;
        real_graph[a].push_back(make_pair(b,i));
    }
    long long int answer=0;
    while(true){
        visited.reset();
        int final=dfs(1,1e9);
        if(final==0)break;
        answer+=final;
    }
    cout<<answer<<'\n';
    edge_visited.reset();
    while(true){
        if(!dfs2(1))break;
    }
    return 0;
}