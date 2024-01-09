#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int path[100010];
vector<int> answer;
bool End=false;
void dfs(int x,int pre){
    if(End)return;
    for(int i=0;i<graph[x].size();i++){
        
        if(graph[x][i]==pre)continue;
        if(path[graph[x][i]]!=0){
            answer.push_back(x);
            while(answer.back()!=graph[x][i]){
                answer.push_back(path[answer.back()]);
            }
            answer.push_back(x);
            cout<<answer.size()<<endl;
            for(int j=0;j<answer.size();j++){
                if(j)cout<<" ";
                cout<<answer[j];
            }
            exit(0);
            End=true;
            return;
        }
        if(End)break;
        path[graph[x][i]]=x;
        dfs(graph[x][i],x);
        if(End)break;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(path,0,sizeof(path));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(path[i]==0){
            path[i]=i;
            dfs(i,0);
        }
        if(End)break;
    }
    if(!End){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}