#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1010];
long long int flow[1010][1010];
long long int tre=510;
bitset<1010> visited;
long long int dfs(int x,long long int final){
    visited[x]=1;
    if(x==1001)return final;
    for(int i=0;i<graph[x].size();i++){
        int next=graph[x][i];
        if(visited[next])continue;
        if(flow[x][next]==0)continue;
        int f=dfs(next,min(final,flow[x][next]));
        if(f>0){
            flow[x][next]-=f;
            flow[next][x]+=f;
            return f;
        }
    }
    return 0;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    memset(flow,0,sizeof(flow));
    bitset<1010> Start;
    bitset<1010> End;
    Start.reset();
    End.reset();
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        if(Start[a]==0){
            flow[0][a]=1;
            graph[0].push_back(a);
            graph[a].push_back(0);
            Start[a]=1;
        }
        if(End[b]==0){
            flow[b+500][1001]=1;
            graph[b+500].push_back(1001);
            graph[1001].push_back(b+500);
            End[b]=1;
        }    
        flow[a][b+500]=1;
        graph[a].push_back(b+500);
        graph[b+500].push_back(a);
    }
    long long int answer=0;
    while(true){
        visited.reset();
        long long int final=dfs(0,1000);
        if(final==0)break;
        answer+=final;
    }
    cout<<answer<<'\n';
    for(int i=0;i<graph[0].size();i++){
        int x=graph[0][i];
        for(int j=0;j<graph[x].size();j++){
            if(flow[x][graph[x][j]]==0 && x<graph[x][j]){
                cout<<x<<" "<<graph[x][j]-500<<'\n';
                break;
            }
        }
    }
    return 0;
}