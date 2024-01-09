#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long int> > graph[100010];
long long int dis[100010];
long long int routes[100010];
int min_flights[100010];
int max_flights[100010];
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
    for(int i=1;i<=n;i++){
        dis[i]=1e16;
        min_flights[i]=1e8;
        max_flights[i]=0;
    }
    min_flights[1]=0;
    routes[1]=1;
    priority_queue<pair<long long int,int>,vector<pair<long long int,int> >,greater<pair<long long int,int> > > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        long long int now_weight=pq.top().first;
        int now_node=pq.top().second;
        pq.pop();
        if(now_weight>dis[now_node])continue;
        for(int i=0;i<graph[now_node].size();i++){
            int next_node=graph[now_node][i].first;
            int next_weight=graph[now_node][i].second;
            if(dis[next_node]<now_weight+next_weight)continue;
            if(dis[next_node]==now_weight+next_weight){
                routes[next_node]=(routes[next_node]+routes[now_node])%1000000007;
                min_flights[next_node]=min(min_flights[now_node]+1,min_flights[next_node]);
                max_flights[next_node]=max(max_flights[now_node]+1,max_flights[next_node]);
            }
            else{
                routes[next_node]=routes[now_node];
                min_flights[next_node]=min_flights[now_node]+1;
                max_flights[next_node]=max_flights[now_node]+1;
                dis[next_node]=now_weight+next_weight;
                pq.push(make_pair(dis[next_node],next_node));
            }
            
        }
    }
    cout<<dis[n]<<" "<<routes[n]<<" "<<min_flights[n]<<" "<<max_flights[n];
    return 0;
}