#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int sum;
map<int,int> go[510];
map<int,int> bac[510];
bool visited[510];
int road[1010];
int dfs(int a,int b,int deep){
    int sub=0;
    //cout<<a<<endl;
    road[deep]=a;
    if(a==n){
        for(int i=deep;i>0;i--){
            //cout<<"1:"<<road[i-1]<<" "<<road[i]<<" "<<-b<<endl;
            go[road[i-1]][road[i]]-=b;
            //cout<<"1:"<<road[i]<<" "<<road[i-1]<<" "<<b<<endl;
            bac[road[i]][road[i-1]]+=b;
        }
        return b;
    }
    else{
        bool door=true;
        visited[a]=true;
        for(auto it=go[a].begin();it!=go[a].end();it++){
            if(visited[it->first])continue;
            if(it->second<sum || it->second==0 || b-sub==0)continue;
            door=false;
            sub+=dfs(it->first,min(it->second,b-sub),deep+1);
        }
        visited[a]=false;
        if(door){
            for(int i=deep;i>0;i--){
                //cout<<"2:"<<road[i-1]<<" "<<road[i]<<" "<<-b<<endl;
                go[road[i-1]][road[i]]-=b;
                //cout<<"2:"<<road[i]<<" "<<road[i-1]<<" "<<b<<endl;
                bac[road[i]][road[i-1]]+=b;
            }
            return b;
        }
    }
    return sub;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    sum=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        go[a][b]=c;
        bac[b][a]=0;
        sum+=c;
    }
    while(sum!=0){
        for(auto it=go[1].begin();it!=go[1].end();it++){
            if(it->second<sum || it->second==0)continue;
            road[0]=1;
            visited[1]=true;
            dfs(it->first,it->second,1);
            visited[1]=false;
        }
        sum/=2;
    }
    long long int answer=0;
    for(auto it=bac[n].begin();it!=bac[n].end();it++){
        answer+=it->second;
    }
    cout<<answer;
    return 0;
}
