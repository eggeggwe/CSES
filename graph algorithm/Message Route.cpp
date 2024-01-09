#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> graph[100010];
int dis[100010];
int path[100010];
bitset<100010> visited;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    visited.reset();
    visited[1]=1;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int next=graph[now][i];
            if(visited[next]==1)continue;
            visited[next]=1;
            q.push(next);
            path[next]=now;
            dis[next]=dis[now]+1;
        }
    }
    path[1]=1;
    
    vector<int> answer;
    if(visited[n]==1){
        cout<<dis[n]+1<<endl;
        int now=n;
        while(n!=1){
            answer.push_back(n);
            n=path[n];
        }
        cout<<1;
        for(int i=answer.size()-1;i>=0;i--){
            cout<<" "<<answer[i];
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}