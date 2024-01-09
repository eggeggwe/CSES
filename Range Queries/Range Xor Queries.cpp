#include <bits/stdc++.h>
using namespace std;
int n,q;
long long int Pre[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        long long int tmp;
        cin>>tmp;
        Pre[i]=tmp^Pre[i-1];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        long long int tmp=Pre[b];
        long long int tmp2=Pre[a-1];
        cout<<(tmp^tmp2)<<'\n';
    }
    return 0;
}