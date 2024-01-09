#include <bits/stdc++.h>
using namespace std;
long long int dis[505][505];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<505;i++){
        for(int j=0;j<505;j++){
            dis[i][j]=1e16;
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(dis[a][b]==1e16)cout<<-1<<'\n';
        else cout<<dis[a][b]<<'\n';
    }
    return 0;
}