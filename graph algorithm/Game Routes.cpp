#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
long long int dp[100010];
void dfs(int a){
    for(int i=0;i<graph[a].size();i++){
        int pre=graph[a][i];
        if(dp[pre]==0)dfs(pre);
        dp[a]=(dp[a]+dp[pre])%1000000007;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[b].push_back(a);
    }
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dfs(n);
    cout<<dp[n];
    return 0;
}