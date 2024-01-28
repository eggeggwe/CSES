#include <bits/stdc++.h>
using namespace std;
long long int a[1010];
multiset<tuple<long long int,int,int> > use;
vector<tuple<long long int,int,int>> use2;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            use.insert(make_tuple(a[i]+a[j],i,j));
            use2.push_back(make_tuple(a[i]+a[j],i,j));
        }
    }
    for(int i=0;i<use2.size();i++){
        long long int tmp2,tmp3,tmp;
        tie(tmp,tmp2,tmp3)=use2[i];
        if(tmp>x)continue;
        auto it=use.lower_bound(make_tuple(x-tmp,0,0));
        while(get<0>(*it)==x-tmp){
            long long int Tmp,Tmp2,Tmp3;
            tie(Tmp,Tmp2,Tmp3)=*it;
            if(tmp2!=Tmp2 && tmp2!=Tmp3 && tmp3!=Tmp2 && tmp3!=Tmp3){
                cout<<tmp2+1<<" "<<tmp3+1<<" "<<Tmp2+1<<" "<<Tmp3+1;
                return 0;
            }
            it++;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}