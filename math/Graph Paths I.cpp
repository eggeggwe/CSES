#include <bits/stdc++.h>
using namespace std;
#define vvll vector<vector<long long int> >
const long long int MOD=1e9+7;
long long int n,m,k;
vvll sup(vvll x,long long int y){
    if(y==1)return x;
    if(y%2==0){
        vvll tmp=sup(x,y/2);
        vvll ans(n,vector<long long int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                long long int sum=0;
                for(int u=0;u<n;u++){
                    sum=(sum+(tmp[i][u]*tmp[u][j])%MOD)%MOD;
                }
                ans[i][j]=sum;
            }
        }
        /*
        for(int i=0;i<n;i++){
            ans[i][i]=1;
        }*/
        return ans;
    }else{
        vvll tmp=sup(x,y-1);
        vvll ans(n,vector<long long int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                long long int sum=0;
                for(int u=0;u<n;u++){
                    sum=(sum+(tmp[i][u]*x[u][j])%MOD)%MOD;
                }
                ans[i][j]=sum;
            }
        }/*
        for(int i=0;i<n;i++){
            ans[i][i]=1;
        }*/
        return ans;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m>>k;
    vvll graph(n,vector<long long int>(n,0));
    for(int i=0;i<m;i++){
        int tmp,tmp2;
        cin>>tmp>>tmp2;
        graph[tmp-1][tmp2-1]++;
    }
    /*
    for(int i=0;i<n;i++){
        graph[i][i]=1;
    }*/
    vvll tmp=sup(graph,k);
    
    cout<<tmp[0][n-1];
    return 0;
}
