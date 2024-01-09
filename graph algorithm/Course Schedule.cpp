#include <bits/stdc++.h>
using namespace std;
int pre[100010];
vector<int> graph[100010];
vector<int> answer;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        pre[b]++;
        graph[a].push_back(b);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(pre[i]==0)q.push(i);
    }
    while(!q.empty()){
        int next=q.front();
        q.pop();
        answer.push_back(next);
        for(int i=0;i<graph[next].size();i++){
            pre[graph[next][i]]--;
            if(pre[graph[next][i]]==0){
                q.push(graph[next][i]);
            }
        }
    }
    if(answer.size()==n){
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<answer[i];
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}