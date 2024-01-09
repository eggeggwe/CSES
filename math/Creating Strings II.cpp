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
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    getline(cin,s);
    int a[30];
    memset(a,0,sizeof(a));
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    long long int sum=0;
    for(int i=0;i<26;i++){
        sum+=a[i];
    }
    frac[1]=1;
    for(long long int i=2;i<=1000000;i++){
        frac[i]=(frac[i-1]*i)%1000000007;
    }
    for(long long int i=1;i<=1000000;i++){
        modneg[i]=modne(frac[i],1000000007);
    }
    long long int answer=frac[sum];
    for(int i=0;i<26;i++){
        if(a[i]!=0){
            answer=(answer*modneg[a[i]])%1000000007;
        }
    }
    cout<<answer;
    return 0;
}