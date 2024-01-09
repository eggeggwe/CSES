#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int in[100010];
int dis[100010];
int path[100010];
vector<int> answer;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(in,0,sizeof(in));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        dis[i]=-1e9;
        if(in[i]==0)q.push(i);
    }
    path[1]=1;
    dis[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int next=graph[now][i];
            if(dis[next]<dis[now]+1){
                dis[next]=dis[now]+1;
                path[next]=now;    
            }
            in[next]--;
            if(in[next]==0)q.push(next);
        }
    }
    if(dis[n]<0){
        cout<<"IMPOSSIBLE";
    }else{
        answer.push_back(n);
        while(answer.back()!=1){
            answer.push_back(path[answer.back()]);
        }
        cout<<answer.size()<<'\n';
        for(int i=answer.size()-1;i>=0;i--){
            if(i!=answer.size())cout<<" ";
            cout<<answer[i];
        }
    }
    return 0;
}