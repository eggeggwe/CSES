#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n;
    cin>>n;
    long long int sum=0;
    long long int i;
    long long int tmp2;
    for(i=1;i*i<=n;i++){
        long long int big=n/i;
        tmp2=n/i;
        long long int tmp=((((1+big)%1000000007)*(big%1000000007))/2)%1000000007;
        sum=(sum+tmp)%1000000007;
    }
    while(i>=tmp2)i--;
    for(;i>=1;i--){
        long long int tmp=((((1+i)%1000000007)*(i%1000000007))/2)%1000000007;
        sum=(sum+(tmp*((n/i-n/(i+1))%1000000007))%1000000007)%1000000007;
    }
    cout<<sum;
    return 0;
}