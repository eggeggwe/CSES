#include <bits/stdc++.h>
using namespace std;
long long int a[200010];
long long int n,t;
bool test(long long int T){
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=T/a[i];
        if(sum>=t)return true;
    }
    return false;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int r=-1,l=1e18;
    while(r+1<l){
        long long int mid=r+(l-r)/2;
        if(test(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}