#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector<long long int> >
vv sup(vv x,long long int y,long long int K){
    if(y==1)return x;
    if(y%2==0){
        vv tmp=sup(x,y/2,K);
        vv answer(2,vector<long long int>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                long long int sum=0;
                for(int k=0;k<2;k++){
                    sum=(sum+tmp[i][k]*tmp[k][j])%K;
                }
                answer[i][j]=sum;
            }
        }
        return answer;
    }else{
        vv answer(2,vector<long long int>(2,0));
        vv tmp=sup(x,y-1,K);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                long long int sum=0;
                for(int k=0;k<2;k++){
                    sum=(sum+x[i][k]*tmp[k][j])%K;
                }
                answer[i][j]=sum;
            }
        }
        return answer;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    
    if(n==0){
        cout<<0;
    }else if(n==1){
        cout<<1;
    }else{
        vv tmp({{0,1},{1,1}});
        vv answer=sup(tmp,n-1,1000000007);
        cout<<answer[1][1];
    }
    return 0;
}