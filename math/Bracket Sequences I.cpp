#include <bits/stdc++.h>
using namespace std;
long long int frac[1000010];
const long long int MOD=1e9+7;
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
    return (sup(a,k-2,k)%k);
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    frac[1]=1;
    for(int i=2;i<=1000000;i++){
        frac[i]=(frac[i-1]*i)%MOD;
    }
    long long int n;
    cin>>n;
    if(n%2==1){
        cout<<0;
    }else if(n==0){
        cout<<1;
    }else{
        cout<<(((frac[n]*modneg(frac[n/2],MOD))%MOD*modneg(frac[n/2],MOD))%MOD*modneg(n/2+1,MOD))%MOD;
    }
    return 0;
}