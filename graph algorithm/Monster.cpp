#include <bits/stdc++.h>
using namespace std;
string graph[1010];
int monster[1010][1010];
int person[1010][1010];
int answer=1000010;
int answern=-1,answerm=-1;
string USE="UDRL";
pair<int,int> use[4]={make_pair(1,0),make_pair(-1,0),make_pair(0,-1),make_pair(0,1)};
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,graph[i]);
    }
    queue<pair<int,int> > q;
    int N,M;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            monster[i][j]=1000100;
            person[i][j]=1000100;
            if(graph[i][j]=='M'){
                q.push(make_pair(i,j));
                monster[i][j]=0;
            }
            if(graph[i][j]=='A'){
                N=i;
                M=j;
                person[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int nown=q.front().first,nowm=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextn=nown+use[i].first,nextm=nowm+use[i].second;
            if(nextn>=n || nextn<0 || nextm>=m || nextm<0)continue;
            if(graph[nextn][nextm]=='#')continue;
            if(monster[nextn][nextm]<=monster[nown][nowm]+1)continue;
            monster[nextn][nextm]=monster[nown][nowm]+1;
            q.push(make_pair(nextn,nextm));
        }
    }
    q.push(make_pair(N,M));
    while(!q.empty()){
        int nown=q.front().first,nowm=q.front().second;
        if(nown==0 || nown==n-1 || nowm==0 || nowm==m-1){
            if(answer>person[nown][nowm] || graph[nown][nowm]=='.'){
                answer=person[nown][nowm];
                answern=nown;
                answerm=nowm;
            }
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nextn=nown+use[i].first,nextm=nowm+use[i].second;
            if(nextn>=n || nextn<0 || nextm>=m || nextm<0)continue;
            if(graph[nextn][nextm]=='#')continue;
            if(monster[nextn][nextm]<=person[nown][nowm]+1)continue;
            if(person[nextn][nextm]<=person[nown][nowm]+1)continue;
            person[nextn][nextm]=person[nown][nowm]+1;
            q.push(make_pair(nextn,nextm));
        }
    }
    if(answer==1000010){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        cout<<answer<<endl;
        string ans="";
        while(graph[answern][answerm]!='A'){
            for(int i=0;i<4;i++){
                int nextn=answern+use[i].first,nextm=answerm+use[i].second;
                if(nextn<0 || nextn>=n || nextm<0 || nextm>=m)continue;
                if(person[nextn][nextm]==person[answern][answerm]-1){
                    ans+=USE[i];
                    answern=nextn;
                    answerm=nextm;
                }
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
    }
    return 0;
}