#include<bits/stdc++.h>
using namespace std;
pair< pair<int,int> ,int> a[200010];
int answer[200010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
    }
    sort(a,a+n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > tmp;
    answer[a[0].second]=1;
    tmp.push(make_pair(a[0].first.second,1));
    for(int i=1;i<n;i++){
        if(tmp.top().first<a[i].first.first){
            answer[a[i].second]=tmp.top().second;
            tmp.push(make_pair(a[i].first.second,tmp.top().second));
            tmp.pop();
        }else{
            answer[a[i].second]=tmp.size()+1;
            tmp.push(make_pair(a[i].first.second,answer[a[i].second]));
        }
    }
    cout<<tmp.size()<<'\n';
    for(int i=0;i<n;i++){
        if(i)cout<<' ';
        cout<<answer[i];
    }
    return 0;
}
