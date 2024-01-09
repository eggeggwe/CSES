#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int>,int> A[200010];
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first!=b.first.first) return a.first.first<b.first.first;
    return a.first.second>b.first.second;
}
int BIT[300010];
void push(int a){
    while(a<300010){
        BIT[a]++;
        a+=a&(-a);
    }
    return;
}
int query(int a){
    int answer=0;
    while(a>0){
        answer+=BIT[a];
        a-=a&(-a);
    }
    return answer;
}
int contain[200010];
int contained[200010];
unordered_map<int,int> tmp;
int Tmp[200010];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i].first.first>>A[i].first.second;
        A[i].second=i;
        Tmp[i]=A[i].first.second;
    }
    sort(A,A+n,cmp);
    sort(Tmp,Tmp+n);
    for(int i=0;i<n;i++){
        tmp[Tmp[i]]=i+1;
    }
    memset(BIT,0,sizeof(BIT));
    for(int i=n-1;i>=0;i--){
        int use=A[i].second;
        int num=tmp[A[i].first.second];
        contain[use]=query(num);
        push(num);
    }
    memset(BIT,0,sizeof(BIT));
    for(int i=0;i<n;i++){
        int use=A[i].second;
        int num=tmp[A[i].first.second];
        contained[use]=query(300000)-query(num-1);
        push(num);
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
