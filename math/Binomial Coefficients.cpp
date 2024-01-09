#include <bits/stdc++.h>
using namespace std;
long long int frac[1000010];
long long int modneg[1000010];
long long int sup(long long int x,long long int y,long long int k){
    if(y==1)return x;
    else if(y%2==0){
        long long int tmp=sup(x,y/2,k);
        return (tmp*tmp)%k;
    }else{
        return (x*sup(x,y-1,k))%k;
    }
}
long long int modne(long long int a,long long int k){
    return sup(a,k-2,k)%k;
}
void solve(){
    long long int a,b;
    cin>>a>>b;
    if(!(a==b || b==0))cout<<((frac[a]*modneg[b])%1000000007*modneg[a-b])%1000000007<<'\n';
    else cout<<1<<'\n';
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    frac[1]=1;
    for(int i=2;i<=1000000;i++){
        frac[i]=(frac[i-1]*i)%1000000007;
    }
    for(int i=1;i<=1000000;i++){
        modneg[i]=modne(frac[i],1000000007);
    }
    while(n--)solve();
    return 0;
}