#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> a[100010];
long long int sup(long long int x,long long int y){
    if(y==1)return x;
    if(y%2==0){
        long long int tmp=sup(x,y/2);
        return (tmp*tmp)%1000000007;
    }else{
        return (x*sup(x,y-1))%1000000007;
    }
}
long long int neg(long long int x){
    if(x==1)return 1;
    return sup(x,1000000007-2);
}
long long int Neg(long long int x){
    if(x==1)return 1;
    return sup(x,1000000006-2);
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].second%2==0){
            odd++;
        }else{
            even++;
        }
    }
    long long int sum=1,Sum=1;
    for(int i=0;i<n;i++){
        sum=(sum*(a[i].second+1))%1000000007;
        Sum=(Sum*(a[i].second+1))%1000000006;
    }
    long long int sum2=1;
    for(int i=0;i<n;i++){
        sum2=(sum2*(sup(a[i].first,a[i].second+1)-1))%1000000007;
    }
    for(int i=0;i<n;i++){
        sum2=(sum2*neg(a[i].first-1))%1000000007;
    }
    long long int sum3=1;
    if(even==0){
        for(int i=0;i<n;i++){
            sum3=(sum3*sup(a[i].first,a[i].second/2))%1000000007;
        }
        sum3=sup(sum3,Sum);
    }else{
        for(int i=0;i<n;i++){
            sum3=(sum3*sup(a[i].first,a[i].second))%1000000007;
        }
        sum3=sup(sum3,Sum*Neg(2));
    }
    cout<<sum<<" "<<sum2<<" "<<sum3;
    return 0;
}