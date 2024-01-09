#include <bits/stdc++.h>
using namespace std;
long long int dp[1000010];
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
    return sup(a,k-2,k)%k;
}
long long int gcd(long long int a,long long int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,m;
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=1000000;i++){
        dp[i]=(dp[i-1]*m)%MOD;
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum=(sum+dp[gcd(i,n)])%MOD;
    }
    cout<<(sum*modneg(n,MOD))%MOD;
    return 0;
}