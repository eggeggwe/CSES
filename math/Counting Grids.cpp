#include <bits/stdc++.h>
using namespace std;
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
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    long long int tmp=0;
    tmp=sup(2,(n*n)%(MOD-1),MOD);
    long long int tmp2=0;
    if(n%2==0){
        tmp2=sup(2,((n/2)*(n/2))%(MOD-1),MOD);
    }else{
        tmp2=sup(2,((n/2)*(n/2+1)+1)%(MOD-1),MOD);
    }
    long long int tmp3=0;
    if(n%2==0){
        tmp3=sup(2,(n*(n/2))%(MOD-1),MOD);
    }else{
        tmp3=sup(2,((n/2)*(n/2+1)*2+1)%(MOD-1),MOD);
    }
    long long int answer=0;
    answer=(answer+tmp)%MOD;
    answer=(answer+tmp2)%MOD;
    answer=(answer+tmp3)%MOD;
    answer=(answer+tmp2)%MOD;
    answer=(answer*modneg(4,MOD))%MOD;
    cout<<answer;
    return 0;
}