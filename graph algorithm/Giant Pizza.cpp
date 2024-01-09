#include <bits/stdc++.h>
using namespace std;
bitset<100010> answer;
bitset<100010> use;
vector<int> graph[200010];
vector<int> graph2[200010];
stack<int> sta;
bitset<200010> visited;
int test_for_impo[100010];
int dsu=1;
int comp[200010];
vector<int> Comp[200010];
vector<int> comp_topo[200010];
int out[200010];
bool ANSWER=true;
int neg(int x){
    return 200001-x;
}
void dfs(int x){
    visited[x]=1;
    for(int i=0;i<graph[x].size();i++){
        if(visited[graph[x][i]])continue;
        dfs(graph[x][i]);
    }
    sta.push(x);
    return;
}
void dfs2(int x){
    visited[x]=0;
    for(int i=0;i<graph2[x].size();i++){
        if(!visited[graph2[x][i]])continue;
        dfs2(graph2[x][i]);
    }
    comp[x]=dsu;
    if(x>100000){
        if(test_for_impo[neg(x)]==0){
            test_for_impo[neg(x)]=dsu;
        }else{
            if(test_for_impo[neg(x)]==dsu){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
    }else{
        if(test_for_impo[x]==0){
            test_for_impo[x]=dsu;
        }else{
            if(test_for_impo[x]==dsu){
                cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
    }
    Comp[dsu].push_back(x);
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        char c,d;
        int a,b;
        cin>>c>>a>>d>>b;
        //cerr<<a<<" "<<b<<endl;
        if(c=='-')a=neg(a);
        if(d=='-')b=neg(b);
        //cerr<<a<<" "<<b<<endl;
        graph[neg(a)].push_back(b);
        graph[neg(b)].push_back(a);
        graph2[b].push_back(neg(a));
        graph2[a].push_back(neg(b));
    }
    visited.reset();
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i);
    }
    for(int i=1;i<=n;i++){
        if(visited[neg(i)])continue;
        dfs(neg(i));
    }
    while(!sta.empty()){
        if(visited[sta.top()]){
            dfs2(sta.top());
            dsu++;
        }
        sta.pop();
    }
    for(int i=1;i<dsu;i++){
        bitset<200010> test;
        test.reset();
        test[i]=1;
        for(int j=0;j<Comp[i].size();j++){
            int tmp=Comp[i][j];
            for(int k=0;k<graph[tmp].size();k++){
                if(test[comp[graph[tmp][k]]])continue;
                out[i]++;
                comp_topo[comp[graph[tmp][k]]].push_back(i);
            }
        }
    }
    queue<int> q;
    for(int i=1;i<dsu;i++){
        if(out[i]==0)q.push(i);
    }
    use.reset();
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<Comp[now].size();i++){
            int tmp=Comp[now][i];
            if(tmp>100000){
                if(use[neg(tmp)])continue;
                answer[neg(tmp)]=0;
                use[neg(tmp)]=1;
            }else{
                if(use[tmp])continue;
                answer[tmp]=1;
                use[tmp]=1;
            }
        }
        for(int i=0;i<comp_topo[now].size();i++){
            out[comp_topo[now][i]]--;
            if(out[comp_topo[now][i]]==0){
                q.push(comp_topo[now][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        if(answer[i]){
            cout<<"+";
        }else{
            cout<<"-";
        }
    }
    return 0;
}