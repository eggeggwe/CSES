#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    long long int answer=0;
    long long int realsum=0;
    int n,sum;
    cin>>n>>sum;
    int j=0;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a[i]=b;
        realsum+=b;
        if(realsum==sum){
            answer++;
        }
        while(j<i&&realsum>sum){
            realsum-=a[j];
            j++;
            if(realsum==sum){
                answer++;
            }
        }
    }
    cout<<answer;
    return 0;
}
