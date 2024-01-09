#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int color[100010];
bool answer=true;
void dfs(int a,int Color){
    color[a]=Color;
    for(int i=0;i<graph[a].size();i++){
        if(color[graph[a][i]]==0){
            if(Color==1){
                dfs(graph[a][i],2);
            }else{
                dfs(graph[a][i],1);
            }
        }else{
            if(color[graph[a][i]]==Color)answer=false;
        }
        if(answer==false)break;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(color,0,sizeof(color));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs(i,1);
        }
    }
    if(answer){
        for(int i=1;i<=n;i++){
            if(i-1)cout<<" ";
            cout<<color[i];
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}