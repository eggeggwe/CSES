#include <bits/stdc++.h>
using namespace std;
long long int a[110];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double sum=0;
    // if(n%2==0){
    //     for(int j=0;j<n;j++/*int i=0;i<n;i++*/){
    //         for(int i=0;i<j;i++/*int j=i+1;j<n;j++*/){
    //             long long int k;
    //             if(a[i]<=a[j]){
    //                 k=((a[i])*(a[i]-1))/2;
    //             }else{
    //                 k=((a[i]-1)+(a[i]-a[j]))*(a[j])/2;
    //             }
    //             sum+=(double)k/(double)(a[i]*a[j]);
    //         }
    //     }
    // }else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int k;
                if(a[i]<=a[j]){
                    k=((a[i])*(a[i]-1))/2;
                }else{
                    k=((a[i]-1)+(a[i]-a[j]))*(a[j])/2;
                }
                sum+=(double)k/(double)(a[i]*a[j]);
            }
        }
    // }
    printf("%.6lf",sum);
    // sum*=1000000;
    // cout<<fixed<<setprecision(6)<<rint(sum)/1000000;
    return 0;
}