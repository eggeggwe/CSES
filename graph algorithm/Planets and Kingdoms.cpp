#include <bits/stdc++.h>
using namespace std;
int low[100010],id[100010];
int ID=0;
bitset<100010> visited;
stack<int> test;
int group[100010];
vector<int> graph[100010];
int groups;
int group_id=1;
void dfs(int a){
    low[a]=id[a]=++ID;
    test.push(a);
    for(int i=0;i<graph[a].size();i++){
        if(!id[graph[a][i]])dfs(graph[a][i]);
        if(!visited[graph[a][i]])low[a]=min(low[a],low[graph[a][i]]);
    }
    if(low[a]==id[a]){
        int tmp;
        do{
            tmp=test.top();
            group[tmp]=group_id;
            visited[tmp]=1;
            test.pop();
            groups--;
        }while(tmp!=a);
        groups++;
        group_id++;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    groups=n;
    memset(id,0,sizeof(id));
    visited.reset();
    for(int i=1;i<=n;i++){
        if(!id[i])dfs(i);
    }
    cout<<groups<<'\n';
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<group[i];
    }
    return 0;
}