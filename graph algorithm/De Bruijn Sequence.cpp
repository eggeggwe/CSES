#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> use;
vector<string> Nodes;
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
    vector<string> node;
    node.push_back("");
    rec(0,node);
    for(int i=0;i<Nodes.size();i++){
        cout<<Nodes[i]<<'\n';
    }
    return 0;
}