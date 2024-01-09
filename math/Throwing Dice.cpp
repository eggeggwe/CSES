#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector<long long int> >
vv sup(vv x,long long int y,long long int k){
    if(y==1)return x;
    if(y%2==0){
        vv tmp=sup(x,y/2,k);
        vv use(6,{0,0,0,0,0,0});
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                long long int sum=0;
                for(int K=0;K<6;K++){
                    sum=(sum+tmp[i][K]*tmp[K][j])%k;
                }
                use[i][j]=sum;
            }
        }
        return use;
    }else{
        vv tmp=sup(x,y-1,k);
        vv use(6,{0,0,0,0,0,0});
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                long long int sum=0;
                for(int K=0;K<6;K++){
                    sum=(sum+x[i][K]*tmp[K][j])%k;
                }
                use[i][j]=sum;
            }
        }
        return use;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    vv use({{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,1,1,1,1,1}});
    int answer[6]={1,2,4,8,16,32};
    if(n<=6){
        cout<<answer[n-1];
    }else{
        vv tmp=sup(use,n-6,1000000007);
        long long int sum=0;
        for(int i=0;i<6;i++){
            sum=(sum+tmp[5][i]*answer[i])%1000000007;
        }
        cout<<sum;
    }
    
    return 0;
}