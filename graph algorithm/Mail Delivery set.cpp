#include <bits/stdc++.h>
using namespace std;
set<int> graph[100010];
vector<int> answer;
void dfs(int x){
    while(graph[x].size()){
        int now=*graph[x].begin();
        graph[now].erase(x);
        graph[x].erase(now);
        dfs(now);
    }
    answer.push_back(x);
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        if(graph[i].size()%2==1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    dfs(1);
    if(answer.size()==m+1){
        for(int i=0;i<answer.size();i++){
            if(i)cout<<" ";
            cout<<answer[i];
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}