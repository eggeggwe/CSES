#include <bits/stdc++.h>
using namespace std;
bitset<1000100> sit;
int a[110];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    sit.reset();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    sit[0]=1;
    for(int i=1;i<=n;i++){
        bool door=false;
        for(int j=0;j<k;j++){
            if(i-a[j]<0)continue;
            door=door||sit[i-a[j]];
        }
        sit[i]=!door;
    }
    for(int i=1;i<=n;i++){
        if(sit[i]){
            cout<<"L";
        }else{
            cout<<"W";
        }
    }
    return 0;
}