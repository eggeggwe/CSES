#include <bits/stdc++.h>
using namespace std;
vector<int> graph[200010];
bitset<200010> visited;
int boss[25][200010];
int deep[200010];
void dfs(int a,int Deep){
    deep[a]=Deep;
    if(visited[a])return;
    visited[a]=true;
    for(int i=0;i<graph[a].size();i++){
        dfs(graph[a][i],Deep+1);
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1);

    return 0;
}