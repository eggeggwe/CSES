#include <bits/stdc++.h>
using namespace std;
const long long int MOD=1e9+7;
long long int frac[1000010];
long long int c[500010];
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
long long int C(long long int a,long long int b){
    if(b==0 || a==b)return 1;
    if(b>a/2){
        //cerr<<a<<" "<<b<<" "<<c[a-b]<<'\n';
        return c[a-b];
    }else{
        c[b]=((frac[a]*modneg(frac[b],MOD))%MOD*modneg(frac[a-b],MOD))%MOD;
        //cerr<<a<<" "<<b<<" "<<c[b]<<"\n";
        return c[b];
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    frac[0]=1;
    frac[1]=1;
    for(long long int i=2;i<=1000000;i++){
        frac[i]=(frac[i-1]*i)%MOD;
    }
    long long int answer=0;
    long long int use=n%2==0?1:-1;
    for(long long int i=0;i<=n;i++){
        if(use==1)answer=(answer+(frac[i]*C(n,i))%MOD*use)%MOD;
        else answer=(answer+MOD+(frac[i]*C(n,i))%MOD*use)%MOD;
        use*=-1;
    }
    cout<<answer;
    return 0;
}