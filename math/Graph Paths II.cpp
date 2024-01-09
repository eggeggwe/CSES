#include <bits/stdc++.h>
using namespace std;
long long int n,m,k;
#define vvll vector<vector<long long int> >
vvll sup(vvll x,long long int y){
    if(y==1) return x;
    if(y%2==0){
        vvll tmp=sup(x,y/2);
        vvll ans(n,vector<long long int>(n,2e18));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int u=0;u<n;u++){
                    ans[i][j]=min(ans[i][j],tmp[i][u]+tmp[u][j]);
                }
            }
        }
        return ans;
    }else{
        vvll tmp=sup(x,y-1);
        vvll ans(n,vector<long long int>(n,2e18));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int u=0;u<n;u++){
                    ans[i][j]=min(ans[i][j],x[i][u]+tmp[u][j]);
                }
            }
        }
        return ans;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    vvll graph(n,vector<long long int>(n,2e18));
    for(int i=0;i<m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        graph[a-1][b-1]=min(graph[a-1][b-1],c);
    }
    vvll tmp=sup(graph,k);
    if(tmp[0][n-1]==(long long int)2e18){
        cout<<-1;
    }else{
        cout<<tmp[0][n-1];
    }
    return 0;
}