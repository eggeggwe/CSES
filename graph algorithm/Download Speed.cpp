#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> graph[510];
long long int flow[510][510];
long long int tre=0;
bitset<510> visited;
long long int dfs(int x,long long int small){
    if(x==n)return small;
    visited[x]=1;
    for(int i=0;i<graph[x].size();i++){
        int next=graph[x][i];
        if(visited[next])continue;
        if(flow[x][next]<tre)continue;
        long long int w=dfs(next,min(small,flow[x][next]));
        if(w>0){
            flow[x][next]-=w;
            flow[next][x]+=w;
            return w;
        }
    }
    return 0;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(flow,0,sizeof(flow));
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        tre=max(tre,c);
        if(flow[a][b]==0 && flow[b][a]==0){
            graph[a].push_back(b);
            graph[b].push_back(a);
            flow[a][b]=c;
        }else{
            flow[a][b]+=c;
        }
    }
    long long int answer=0;
    while(tre>0){
        while(true){
            visited.reset();
            long long int f=1e18;
            f=dfs(1,f);
            answer+=f;
            if(f==0)break;
        }
        tre/=2;
    }
    cout<<answer;
    return 0;
}