#include <bits/stdc++.h>
using namespace std;
string s;
set<string> answer;
int per[10];
bool test[10];
void Per(int j){
    if(j==s.size()){
        string tmp="";
        for(int i=0;i<s.size();i++){
            tmp+=s[per[i]];
        }
        answer.insert(tmp);
        return;
    }
    for(int i=0;i<s.size();i++){
        if(test[i]) continue;
        per[j]=i;
        test[i]=1;
        Per(j+1);
        test[i]=0;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(test,0,sizeof(test));
    getline(cin,s);
    Per(0);
    cout<<answer.size()<<'\n';
    for(auto i:answer){
        cout<<i<<'\n';
    }
    return 0;
}