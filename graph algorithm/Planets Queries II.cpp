#include <bits/stdc++.h>
using namespace std;
int graph[200010];
//index go to the value in graph
vector<int> graph2[200010];
//value go to the index in graph
unordered_map<int,int> cycle;//id of node,id of cycle where the node in
//if second<0->the node belong a tree,and the tree belongs to cycle second*-1
//if second==0->the node has not been visited
unordered_map<int,int> cycleid;//id of node,id of node in the cycle where it belong
int cyclesize[200010];
unordered_map<int,int> tree;//id of node,id of tree where the noode in
unordered_map<int,int> treeid;//id of node,id of node in the tree where it belong
unordered_map<int,int> belong;//id of node,the number the tree of node belongs to
int little_point[200010]; 
int visited[200010];
int binary_jump[200010][25];
//for the use of checking if a node visited of not
int find(int x,int d){
    for(int i=0;i<20;i++){
        if(d&(1<<i)){
            x=binary_jump[x][i];
        }
    }
    return x;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>graph[i];
        graph2[graph[i]].push_back(i);
        binary_jump[i][0]=graph[i];
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            binary_jump[j][i]=binary_jump[binary_jump[j][i-1]][i-1];
        }
    }
    queue<int> heads;//the vector stored heads of trees
    int I=1;//id of cycles
    int I2=1;//id of tree;
    int I3=-1;
    for(int i=1;i<=n;i++){
        if(cycle[i]!=0)continue;
        int tmp=i;
        while(visited[tmp]!=I){
            visited[tmp]=I;
            tmp=graph[tmp];
        }
        int J=1;//id in cycle
        while(cycle[tmp]!=I){
            cycle[tmp]=I;
            cycleid[tmp]=J;
            J++;
            if(graph2[tmp].size()>1){
                heads.push(tmp);
            }
            tmp=graph[tmp];
        }
        cyclesize[I]=J-1;
        while(!heads.empty()){
            //cerr<<"give tree id\n";
            int tmp2=heads.front();
            little_point[tmp2]=tmp2;
            //id in tree right now
            for(int j=0;j<graph2[tmp2].size();j++){
                if(cycle[graph2[tmp2][j]]>=1)continue;
                queue<pair<int,int> > q;
                q.push(make_pair(graph2[tmp2][j],1));
                little_point[graph2[tmp2][j]]=graph2[tmp2][j];
                while(!q.empty()){
                    int now,id;
                    tie(now,id)=q.front();
                    q.pop();
                    cycle[now]=I3;
                    tree[now]=I2;
                    treeid[now]=id;
                    belong[now]=tmp2;
                    for(int k=0;k<graph2[now].size();k++){
                        if(graph2[now].size()==1){
                            little_point[graph2[now][k]]=little_point[now];
                        }else{
                            little_point[graph2[now][k]]=graph2[now][k];
                        }
                        q.push(make_pair(graph2[now][k],id+1));
                    }
                }
                I2++;
            }
            heads.pop();
        }
        I3--;
        I++;
    }
    // for(int i=1;i<=n;i++){
    //     if(cycle[i]>=1){
    //         cerr<<i<<" cycle"<<cycle[i]<<":"<<cycleid[i]<<'\n';
    //         cerr<<"the size of cycle["<<cycle[i]<<"]:"<<cyclesize[cycle[i]]<<'\n';
    //     }else{
    //         cerr<<i<<" tree"<<tree[i]<<":"<<treeid[i]<<'\n';
    //         cerr<<"tree"<<tree[i]<<" belongs to "<<belong[i]<<'\n';
    //     }
    // }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(cycle[a]>=1 && cycle[b]>=1){
            if(cycle[a]!=cycle[b]){
                cout<<-1<<'\n';
            }else{
                if(cycleid[a]<=cycleid[b]){
                    cout<<cycleid[b]-cycleid[a]<<'\n';
                }else{
                    cout<<cyclesize[cycle[a]]-cycleid[a]+cycleid[b]<<'\n';
                }
            }    
        }else if(cycle[a]>=1 || cycle[b]>=1){
            if(cycle[a]>=1){
                //cerr<<"stupid\n";
                cout<<-1<<'\n';
                continue;
            }
            //a on tree and b on cycle
            if(cycle[b]*-1!=cycle[a]){
                //cerr<<"haha\n";
                cout<<-1<<'\n';
            }else{
                int tmp=belong[a];
                if(cycleid[tmp]==cycleid[b]){
                    cout<<treeid[a]<<'\n';
                }else if(cycleid[tmp]<cycleid[b]){
                    cout<<cycleid[b]-cycleid[tmp]+treeid[a]<<'\n';
                }else{
                    cout<<cyclesize[cycle[tmp]]-cycleid[tmp]+cycleid[b]+treeid[a]<<'\n';
                }
            }
        }else{
            if(tree[a]!=tree[b]){
                cout<<-1<<'\n';
            }else{
                if(treeid[a]<treeid[b]){
                    cout<<-1<<'\n';
                }else{
                    if(find(a,treeid[a]-treeid[b])==b)cout<<treeid[a]-treeid[b]<<'\n';
                    else cout<<-1<<'\n';
                }
            }
        }
    }
    return 0;
}