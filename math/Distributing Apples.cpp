#include <bits/stdc++.h>
using namespace std;
long long int frac[2000010];
long long int sup(long long int x,long long int y,long long int k){
    if(y==1)return x;
    if(y%2==0){
        long long int tmp=sup(x,y/2,k);
        return (tmp*tmp)%k;
    }else{
        return (x*sup(x,y-1,k))%k;
    }
}
long long int modneg(long long int a,long long int k){
    return sup(a,k-2,k)%k;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,m;
    cin>>n>>m;
    long long int tmp=n+m-1;
    n--;
    frac[1]=1;
    for(long long int i=2;i<=2000000;i++){
        frac[i]=(frac[i-1]*i)%1000000007;
    }
    if(n==0)cout<<1;
    else cout<<((frac[tmp]*modneg(frac[n],1000000007))%1000000007*modneg(frac[m],1000000007))%1000000007;
    return 0;
}