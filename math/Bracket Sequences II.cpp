#include <bits/stdc++.h>
using namespace std;
long long int frac[1000010];
const long long int MOD=1e9+7;
long long int sup(long long int x,long long int y,long long int k){
    if(y==1) return x;
    else if(y%2==0){
        long long int tmp=sup(x,y/2,k);
        return (tmp*tmp)%k;
    }else{
        return (x*sup(x,y-1,k))%k;
    }
}
long long int modneg(long long int a,long long int k){
    return (sup(a,k-2,k))%k;
}
long long int c(long long int a,long long int b){
    if(b==0 || a==b)return 1;
    return ((frac[a]*modneg(frac[b],MOD))%MOD*modneg(frac[a-b],MOD))%MOD;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    string s;
    long long int left=n/2,right=n/2;
    long long int realleft=0,realright=0;
    cin.get();
    getline(cin,s);
    bool test=false;
    if(n%2==1)test=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            left--;
            realleft++;
        }else{
            right--;
            realright++;
        }
        if(realright>realleft || realright>n/2 || realleft>n/2){
            test=true;
        }
    }
    if(test){
        cout<<0;
    }else{
        frac[1]=1;
        for(int i=2;i<=1000000;i++){
            frac[i]=(frac[i-1]*i)%MOD;
        }
        long long int tmp;
        tmp=c(left+right,right);
        //tmp=((frac[left+right]*modneg(frac[right],MOD))%MOD*modneg(frac[left],MOD))%MOD;
        long long int tmp2;
        tmp2=c(left+right,right-(realleft-realright+1));
        //tmp2=((frac[left+right]*modneg(frac[right-(realleft-realright+1)],MOD))%MOD*modneg(frac[left+(realleft-realright+1)],MOD))%MOD;
        cout<<(tmp+(MOD-tmp2))%MOD;
    }
    return 0;
}