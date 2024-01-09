#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int path[100010];
int visited[100010];
vector<int> answer;
bool IMP=true;
void dfs(int a){
    visited[a]=1;
    for(int i=0;i<graph[a].size();i++){
        int next=graph[a][i];
        if(visited[next]==2)continue;
        if(visited[next]==1){
            answer.push_back(a);
            while(answer.back()!=next){
                answer.push_back(path[answer.back()]);
            }
            answer.push_back(a);
            cout<<answer.size()<<'\n';
            for(int i=answer.size()-1;i>=0;i--){
                if(i!=answer.size()-1)cout<<" ";
                cout<<answer[i];
            }
            IMP=false;
        }
        if(!IMP)return;
        path[next]=a;
        dfs(next);
        if(!IMP)return;
    }
    if(!IMP)return;
    visited[a]=2;
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
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            path[i]=i;
            dfs(i);
        }
        if(!IMP)break;
    }
    if(IMP){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}