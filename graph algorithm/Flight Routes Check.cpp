#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int low[100010],id[100010];
int ID=0;
stack<int> test;
bitset<100010> visited;
map<int,bool> Test;
int group[100010];
int A=-1,B=-1;
void dfs(int a){
    low[a]=id[a]=++ID;
    test.push(a);
    for(int i=0;i<graph[a].size();i++){
        if(!id[graph[a][i]])dfs(graph[a][i]);
        if(!visited[graph[a][i]])low[a]=min(low[a],low[graph[a][i]]);
        else{
            A=a;
            B=graph[a][i];
        }
    }
    if(low[a]==id[a]){
        int tmp;
        do{
            tmp=test.top();
            group[tmp]=a;
            visited[tmp]=1;
            test.pop();
        }while(tmp!=a);
    }
    return;
}
bool DFS(int a,int tester){
    bool TEST=false;
    visited[a]=1;
    for(int i=0;i<graph[a].size();i++){
        if(visited[graph[a][i]])continue;
        if(graph[a][i]==tester)return true;
        TEST=TEST|DFS(graph[a][i],tester);
    }
    return TEST;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    visited.reset();
    int n,m;
    cin>>n>>m;
    memset(id,0,sizeof(id));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        if(a==1)Test[b]=1;
    }
    dfs(1);
    
    bool door=true;
    for(int i=2;i<=n;i++){
        if(group[i]!=group[1]){
            door=false;
            cout<<"NO\n";
            visited.reset();
            if(DFS(1,i))cout<<i<<" "<<1;
            else cout<<1<<" "<<i;
            break;
        }
    }
    if(door)cout<<"YES";
    /*
    if(A!=-1 && B!=-1){
        cout<<"NO\n";
        cout<<B<<' '<<A;
    }else{
        cout<<"YES";
    }*/
    return 0;
}