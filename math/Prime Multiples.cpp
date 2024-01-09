#include <bits/stdc++.h>
using namespace std;
long long int a[30];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    long long int sum=0;
    for(int i=1;i<(1<<k);i++){
        int num=0;
        long long int use=1;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                if(n/a[j]<use){
                    use=0;
                    break;
                }
                use*=a[j];
                num++;
            }
        }
        if(use==0)continue;
        if(num%2==0){
            sum-=n/use;
        }else{
            sum+=n/use;
        }
    }
    cout<<sum;
    return 0;
}