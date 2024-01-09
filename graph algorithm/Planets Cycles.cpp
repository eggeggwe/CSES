#include <bits/stdc++.h>
using namespace std;
int graph[200010];
vector<int> graph2[200010];
int dp[200010];
bitset<200010> cycle;
bitset<200010> incycle;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>graph[i];
        graph2[graph[i]].push_back(i);
    }
    cycle.reset();
    incycle.reset();
    queue<int> heads;
    for(int i=1;i<=n;i++){
        //cerr<<dp[i]<<" ";
        if(cycle[i])continue;
        int tmp=i;
        while(cycle[tmp]!=1){
            cycle[tmp]=1;
            tmp=graph[tmp];
        }
        int J=1;
        int tmp2=graph[tmp];
        incycle[tmp]=1;
        while(tmp2!=tmp){
            incycle[tmp2]=1;
            //cerr<<tmp2<<endl;
            if(graph2[tmp2].size()>1){
                heads.push(tmp2);
            }
            J++;
            tmp2=graph[tmp2];
        }
        if(graph2[tmp].size()>1){
            heads.push(tmp);
        }
        tmp2=graph[tmp];
        while(tmp2!=tmp){
            //cerr<<tmp2<<endl;
            dp[tmp2]=J;
            tmp2=graph[tmp2];
        }
        dp[tmp]=J;
        while(!heads.empty()){
            int tmp3=heads.front();
            heads.pop();
            queue<pair<int,int> > q;
            for(int j=0;j<graph2[tmp3].size();j++){
                if(incycle[graph2[tmp3][j]])continue;
                q.push(make_pair(graph2[tmp3][j],dp[tmp3]+1));
            }
            while(!q.empty()){
                int now,num;
                tie(now,num)=q.front();
                q.pop();
                dp[now]=num;
                cycle[now]=1;
                for(int k=0;k<graph2[now].size();k++){
                    q.push(make_pair(graph2[now][k],num+1));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<dp[i];
    }
    return 0;
}