#include <bits/stdc++.h>
using namespace std;
vector<int> graph[510];
long long int flow[510][510];
long long int tre=1e18;
int n,m;
bitset<510> visited;
vector<pair<int,int> > ans_path;
long long int dfs(int x,long long int final){
    //cerr<<x<<endl;
    visited[x]=1;
    if(x==n)return final;
    for(int i=0;i<graph[x].size();i++){
        int next=graph[x][i];
        if(flow[x][next]==0)continue;
        if(visited[next])continue;
        int f=dfs(next,min(final,flow[x][next]));
        if(f!=0){
            flow[x][next]-=f;
            flow[next][x]+=f;
            return f;
        }
    }
    return 0;
}
void dfs2(int x){
    //cerr<<x<<endl;
    visited[x]=1;
    for(int i=0;i<graph[x].size();i++){
        int next=graph[x][i];
        if(visited[next])continue;
        if(flow[x][next]==0)continue;
        dfs2(next);
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        flow[a][b]=1;
        flow[b][a]=1;
    }
    long long int answer=0;
    while(tre>0){
        while(true){
            visited.reset();
            int final=dfs(1,1e18);
            //cerr<<endl;
            if(final==0)break;
            answer+=final;
        }
        tre/=2;
    }
    visited.reset();
    dfs2(1);
    for(int i=1;i<=n;i++){
        if(!visited[i])continue;
        for(int j=0;j<graph[i].size();j++){
            int next=graph[i][j];
            if(visited[i] && !visited[next]){
                ans_path.push_back(make_pair(i,next));
            }
        }
    }
    cout<<answer<<'\n';
    for(int i=0;i<ans_path.size();i++){
        cout<<ans_path[i].first<<" "<<ans_path[i].second<<'\n';
    }
    return 0;
}