#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> use;
unordered_map<int,string> ans;
vector<string> Nodes;
queue<pair<int,int> > graph[40000];
bitset<80010> visited;
int n;
void rec(int deep,vector<string> node){
    if(deep==n-1){
        for(int i=0;i<node.size();i++){
            use[node[i]]=i;
            Nodes.push_back(node[i]);
        }
        return;
    }
    vector<string> tmp;
    for(int i=0;i<node.size();i++){
        string tmp2=node[i];
        tmp.push_back(tmp2+'0');
        tmp.push_back(tmp2+'1');
    }
    rec(deep+1,tmp);
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<"01";
        return 0;
    }
    visited.set();
    vector<string> node;
    node.push_back("");
    rec(0,node);
    for(int i=0;i<Nodes.size();i++){
        use[Nodes[i]]=i;
        ans[i]=Nodes[i];
        //cout<<Nodes[i]<<'\n';
    }
    for(int i=0;i<Nodes.size();i++){
        string tmp=Nodes[i];
        string tmp2="";
        for(int j=1;j<tmp.size();j++){
            tmp2+=tmp[j];
        }
        //cerr<<tmp<<" "<<tmp2<<endl;
        graph[use[tmp]].push(make_pair(use[tmp2+'0'],i*2));
        graph[use[tmp]].push(make_pair(use[tmp2+'1'],i*2+1));
    }
    stack<int> sta;
    vector<int> answer;
    sta.push(0);
    while(!sta.empty()){
        int now=sta.top();
        bool door=true;
        while(!graph[now].empty()){
            int next,id;
            tie(next,id)=graph[now].front();
            graph[now].pop();
            if(visited[id]){
                visited[id]=0;
                sta.push(next);
                door=false;
                break;   
            }
        }
        if(door){
            answer.push_back(sta.top());
            sta.pop();
        }
    }
    // cout<<endl;
    // for(int i=0;i<answer.size();i++){
    //     cout<<answer[i]<<" ";
    // }
    cout<<endl;
    cout<<ans[0];
    for(int i=answer.size()-2;i>=0;i--){
        string tmp=ans[answer[i]];
        cout<<tmp[tmp.size()-1];
    }
    return 0;
}