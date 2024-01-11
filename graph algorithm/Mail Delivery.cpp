#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > graph[100010];
bitset<200010> visited;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    visited.reset();
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(make_pair(b,i));
        graph[b].push_back(make_pair(a,i));
    }
    for(int i=1;i<=n;i++){
        if(graph[i].size()%2==1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    stack<int> q;
    q.push(1);
    vector<int> answer;
    while(!q.empty()){
        int now=q.top();
        bool End=1;
        while(!graph[now].empty()){
            int next,id;
            tie(next,id)=graph[now].back();
            graph[now].pop_back();
            if(!visited[id]){
                q.push(next);
                End=0;
                visited[id]=1;
                break;
            }
        }
        if(End){
            answer.push_back(q.top());
            q.pop();
        }
    }
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