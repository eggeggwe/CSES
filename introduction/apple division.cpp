#include <bits/stdc++.h>
using namespace std;
int a[25];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int answer=1e13;
    for(int i=0;i<(1<<n);i++){
        long long int A=0,B=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                A+=a[j];
            }else{
                B+=a[j];
            }
        }
        answer=min(answer,abs(A-B));
    }
    cout<<answer;
    return 0;
}