#include <bits/stdc++.h>
using namespace std;
int boss[25][200010];
vector<int> graph[200010];
int deep[200010];
bitset<200010> visited;
void dfs(int a,int Deep){
    if(visited[a])return;
    visited[a]=true;
    deep[a]=Deep;
    for(int i=0;i<graph[a].size();i++){
        dfs(graph[a][i],Deep+1);
    }
    return;
}
int jump(int a,int b){
    for(int i=0;i<=20;i++){
        if(b&(1<<i))a=boss[i][a];
        if(a==0)break;
    }
    return a;
}
void LCA(int a,int b){
    if(deep[a]<deep[b])swap(a,b);
    a=jump(a,deep[a]-deep[b]);
    if(a==b){
        cout<<a<<'\n';
        return;
    }
    for(int i=20;i>=0;i--){
        if(deep[a]<(1<<i))continue;
        int Ta=boss[i][a],Tb=boss[i][b];
        if(Ta!=Tb && Ta!=0){
            a=Ta;
            b=Tb;
        }
    }
    if(a!=1)a=boss[0][a];
    cout<<a<<'\n';
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>boss[0][i];
        graph[boss[0][i]].push_back(i);
    }
    boss[0][1]=0;
    for(int i=1;i<=20;i++){
        boss[i][1]=0;
        for(int j=2;j<=n;j++){
            boss[i][j]=boss[i-1][boss[i-1][j]];
        }
    }
    dfs(1,1);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        LCA(a,b);
    }
    return 0;
}