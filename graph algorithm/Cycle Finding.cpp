#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,long long int> > graph;
int path[2510];
long long int dis[2510];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        graph.push_back(make_tuple(a,b,c));
    }
    for(int i=0;i<2505;i++){
        dis[i]=1e16;
    }
    dis[1]=0;
    int ptr=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a,b;
            long long int c;
            tie(a,b,c)=graph[j];
            if(dis[b]>dis[a]+c){
                if(i==n-1)ptr=b;
                path[b]=a;
            }
            dis[b]=min(dis[b],dis[a]+c);
        }
    }
    
    if(ptr!=-1){
        for(int i = 0; i < n; i++)ptr = path[ptr];
        cout<<"YES\n";
        vector<int> answer;
        answer.push_back(ptr);
        while(answer[0]!=path[ptr]){
            ptr=path[ptr];
            answer.push_back(ptr);
        }
        answer.push_back(path[ptr]);
        for(int i=answer.size()-1;i>=0;i--){
            if(i!=answer.size()-1)cout<<" ";
            cout<<answer[i];
        }
    }else{
        cout<<"NO";
    }
    return 0;
}