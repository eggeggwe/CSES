#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<long long int,int> tmp;
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    tmp[0]++;
    long long int answer=0,realsum=0;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        realsum+=b;
        answer+=tmp[realsum-sum];
        tmp[realsum]++;
    }
    cout<<answer;
    return 0;
}
