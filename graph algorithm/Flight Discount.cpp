#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long int> > graph[100010];
long long int dis[2][100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    for(int i=0;i<100005;i++){
        for(int j=0;j<2;j++){
            dis[j][i]=1e18;
        }
    }
    dis[0][1]=0;
    priority_queue<tuple<long long int,int,int>,vector<tuple<long long int,int,int> >,greater<tuple<long long int,int,int> > > pq;
    pq.push(make_tuple(0,1,0));
    while(!pq.empty()){
        long long int now_weight=get<0>(pq.top());
        int now_node=get<1>(pq.top());
        int now_discount=get<2>(pq.top());
        pq.pop();
        if(dis[now_discount][now_node]!=now_weight)continue;
        for(int i=0;i<graph[now_node].size();i++){
            long long int next_weight=graph[now_node][i].second;
            int next_node=graph[now_node][i].first;
            if(dis[now_discount][now_node]+next_weight<dis[now_discount][next_node]){
                dis[now_discount][next_node]=dis[now_discount][now_node]+next_weight;
                pq.push(make_tuple(dis[now_discount][next_node],next_node,now_discount));
            }
            if(now_discount==0){
                if(dis[now_discount][now_node]+next_weight/2<dis[1][next_node]){
                    dis[1][next_node]=dis[now_discount][now_node]+next_weight/2;
                    pq.push(make_tuple(dis[1][next_node],next_node,1));
                }
            }
        }
    }
    cout<<dis[1][n];
    return 0;
}