#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long int> > graph[100010];
vector<long long int> answer[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    priority_queue<pair<long long int,int>,vector<pair<long long int,int> >,greater<pair<long long int,int> > > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        long long int now_weight=pq.top().first;
        int now_node=pq.top().second;
        pq.pop();
        if(answer[now_node].size()==q)continue;
        answer[now_node].push_back(now_weight);
        for(int i=0;i<graph[now_node].size();i++){
            int next_node=graph[now_node][i].first;
            long long int next_weight=graph[now_node][i].second;
            pq.push(make_pair(now_weight+next_weight,next_node));
        }
    }
    for(int i=0;i<q;i++){
        if(i)cout<<" ";
        cout<<answer[n][i];
    }
    return 0;
}