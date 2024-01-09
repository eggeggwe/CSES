#include <bits/stdc++.h>
using namespace std;
long long int coin[100010];
vector<int> graph[100010];
vector<int> graph2[100010];
stack<int> sta;
bitset<100010> visited;
int dsu=1;
int comp[100010];
bitset<100010> comp_visited;
vector<int> comp_set[100010];
vector<int> comp_graph[100010];
long long int comp_in[100010];
long long int comp_sum[100010];
long long int answer=0;
long long int comp_answer[100010];
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
    for(int i=0;i<graph2[x].size();i++){
        if(!visited[graph2[x][i]])continue;
        dfs2(graph2[x][i]);
    }
    comp[x]=dsu;
    comp_set[dsu].push_back(x);
    comp_sum[dsu]+=coin[x];
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
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
    for(int i=1;i<dsu;i++){
        bitset<100010> test;
        test.reset();
        test[i]=1;
        for(int j=0;j<comp_set[i].size();j++){
            int tmp=comp_set[i][j];
            for(int k=0;k<graph[tmp].size();k++){
                int tmp2=graph[tmp][k];
                if(test[comp[tmp2]] || i==comp[tmp2])continue;
                test[comp[tmp2]]=1;
                comp_in[comp[tmp2]]++;
                comp_graph[i].push_back(comp[tmp2]);
            }
        }
    }
    queue<int> q;
    for(int i=1;i<dsu;i++){
        if(comp_in[i]==0){
            q.push(i);
            comp_answer[i]=comp_sum[i];
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        answer=max(answer,comp_answer[now]);
        for(int i=0;i<comp_graph[now].size();i++){
            int tmp=comp_graph[now][i];
            comp_answer[tmp]=max(comp_answer[tmp],comp_answer[now]+comp_sum[tmp]);
            comp_in[tmp]--;
            if(comp_in[tmp]==0)q.push(tmp);
        }
    }
    cout<<answer;
    return 0;
}