#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int> ,int> A[200010];
bool cmp(pair<pair<int,int> ,int> a,pair<pair<int,int> ,int> b){
    if(a.first.first!=b.first.first) return a.first.first<b.first.first;
    return a.first.second>b.first.second;
}
int contain[200010];
int contained[200010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        A[i].first.first=a;
        A[i].first.second=b;
        A[i].second=i;
    }
    sort(A,A+n,cmp);
    int now=2e9;
    for(int i=n-1;i>=0;i--){
        int use=A[i].second;
        if(now<=A[i].first.second){
            contain[use]=1;
        }else{
            contain[use]=0;
            now=A[i].first.second;
        }
    }
    now=-1;
    for(int i=0;i<n;i++){
        int use=A[i].second;
        if(now>=A[i].first.second){
            contained[use]=1;
        }else{
            contained[use]=0;
            now=A[i].first.second;
        }
    }
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<contain[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<contained[i];
    }
    return 0;
}
