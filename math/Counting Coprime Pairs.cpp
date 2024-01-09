#include <bits/stdc++.h>
using namespace std;
int a[100010];
int mobius[1000010];
vector<int> prime;
int cnt[1000010];
int least_factor[1000010];
void least(){
    least_factor[1]=1;
    for(int i=2;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            if(least_factor[j]==0)least_factor[j]=i;
        }
    }
    return;
}
void Mob(){
    mobius[1]=1;
    for(int i=2;i<=1000000;i++){
        if(least_factor[i/least_factor[i]]==least_factor[i])mobius[i]=0;
        else mobius[i]=-1*mobius[i/least_factor[i]];
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    least();
    Mob();
    long long int answer=0;
    for(int i=1;i<=1000000;i++){
        long long int sum=0;
        for(int j=i;j<=1000000;j+=i){
            sum+=cnt[j];
        }
        if(i==1)answer+=((sum-1)*sum/2);
        else if(mobius[i]!=0)answer+=((sum-1)*sum/2)*mobius[i];
    }
    cout<<answer;
    return 0;
}