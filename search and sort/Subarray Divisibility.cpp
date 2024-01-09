#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long int answer=0,realsum=0;
    unordered_map<long long int,int> tmp;//positive
    unordered_map<long long int,int> tmp2;//negative
    tmp[0]++;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        realsum+=b;
        if(realsum>=0){
            answer+=tmp[n-realsum%n];
            answer+=tmp2[realsum%n];
        }else{
            answer+=tmp[realsum%n];
            answer+=tmp2[n-realsum%n];
        }
        if(realsum>=0){
            tmp[realsum%n]++;
        }else{
            tmp2[realsum%n]++;
        }
    }
    cout<<answer;
    return 0;
}
