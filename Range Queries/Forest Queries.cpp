#include <bits/stdc++.h>
using namespace std;
long long int Pre[1010][1010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    cin.get();
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        for(int j=0;j<n;j++){
            if(s[j]=='.'){
                Pre[i][j+1]=Pre[i-1][j+1]+Pre[i][j]-Pre[i-1][j];
            }else{
                Pre[i][j+1]=Pre[i-1][j+1]+Pre[i][j]-Pre[i-1][j]+1;
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<Pre[c][d]-Pre[c][b-1]-Pre[a-1][d]+Pre[a-1][b-1]<<'\n';
    }
    return 0;
}