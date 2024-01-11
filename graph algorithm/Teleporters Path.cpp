#include <bits/stdc++.h>
using namespace std;
bitset<200010> visited;
vector<pair<int,int> > graph[100010];
int in[100010],out[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(make_pair(b,i));
        out[a]++;
        in[b]++;
    }
    int A=-1,B=-1;
    for(int i=1;i<=n;i++){
        
        if(in[i]+1==out[i]){
            if(A!=-1){
                cout<<"IMPOSSIBLE";
                return 0;
            }else{
                A=i;
            }
        }else if(in[i]==out[i]+1){
            if(B!=-1){
                cout<<"IMPOSSIBLE";
                return 0;
            }else{
                B=i;
            }
        }else if(in[i]!=out[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
        //cerr<<i<<" : ";
        for(int j=0;j<graph[i].size();j++){
            if(j)cerr<<" ";
            //cerr<<graph[i][j].first;
        }
        //cerr<<endl;
        //reverse(graph[i].begin(),graph[i].end());
    }
    if(A!=1 || B!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    graph[B].push_back(make_pair(A,m));
    vector<int> path;
    stack<int> sta;
    sta.push(1);
    while(!sta.empty()){
        int now=sta.top();
        bool End=1;
        if(!graph[now].empty()){
            int next,id;
            tie(next,id)=graph[now].back();
            graph[now].pop_back();
            End=0;
            sta.push(next);
        }
        if(End){
            path.push_back(sta.top());
            sta.pop();
        }
    }
    
    if(path.size()==m+2){
        reverse(path.begin(),path.end());
        path.pop_back();
        int j;
        for(j=0;j<path.size();j++){
            if(path[j]==B && path[(j+1)%path.size()]==A){
                j=(j+1)%path.size();
                break;
            }
        }
        for(int i=0;i<path.size();i++){
            if(i)cout<<" ";
            cout<<path[(j+i)%path.size()];
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}