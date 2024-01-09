#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > graph[100010];
long long int dis[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=0;i<100010;i++){
        dis[i]=1e16;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].emplace_back(make_pair(b,c));
    }
    priority_queue<pair<long long int,int>,vector<pair<long long int,int> >,greater<pair<long long int,int> > > pq;
    pq.emplace(make_pair(0,1));
    dis[1]=0;
    while(!pq.empty()){
        int nowwight=pq.top().first,nownode=pq.top().second;
        pq.pop();
        if(dis[nownode]<nowwight)continue;
        for(int i=0;i<graph[nownode].size();i++){
            int nextnode=graph[nownode][i].first,edgew=graph[nownode][i].second;
            if(dis[nextnode]>dis[nownode]+edgew){
                dis[nextnode]=dis[nownode]+edgew;
                pq.emplace(make_pair(dis[nextnode],nextnode));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<dis[i];
    }
    return 0;
}