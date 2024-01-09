#include<bits/stdc++.h>
using namespace std;
int num[200010];
vector<int> graph[200010];
map<int,bool> visited[200010];
int answer[200010];
int n,m;
bool finished=false;
void dfs(int a,int deep){
    num[a]--;
    if(num[1]==0 && deep!=m+1){
        num[a]++;
        return;
    }
    if(deep!=m+1)answer[deep]=a;
    else if(a==1){
        answer[deep]=1;
        finished=true;
    }
    for(int i=0;i<graph[a].size();i++){
        if(visited[a][graph[a][i]] || visited[graph[a][i]][a])continue;
        visited[a][graph[a][i]]=true;
        visited[graph[a][i]][a]=true;
        dfs(graph[a][i],deep+1);
        if(finished)break;
        visited[a][graph[a][i]]=false;
        visited[graph[a][i]][a]=false;
    }
    num[a]++;
    return;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        num[a]++;
        num[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
        visited[a][b]=false;
        visited[b][a]=false;
    }
    bool door=true;
    for(int i=0;i<=n;i++){
        if(num[i]%2==1)door=false;
    }
    if(door){
        dfs(1,1);
        if(answer[m+1]==0){
            cout<<"IMPOSSIBLE";
        }else{
            for(int i=1;i<=m+1;i++){
                if(i-1)cout<<" ";
                cout<<answer[i];
            }
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
