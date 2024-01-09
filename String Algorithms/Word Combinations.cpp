#include <bits/stdc++.h>
using namespace std;
int trie[4010][30];
long long int record[4010][30];
long long int dp[4010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    getline(cin,s);
    int k;
    cin>>k;
    memset(trie,0,sizeof(trie));
    memset(record,0,sizeof(record));
    memset(dp,0,sizeof(dp));
    cin.get();
    while(k--){
        string tmp;
        getline(cin,tmp);
        trie[1][tmp[0]-'a']=1;
        for(int i=1;i<tmp.size();i++){
            trie[i+1][tmp[i]-'a']=trie[i][tmp[i-1]-'a']+1;
        }
        record[tmp.size()][tmp[tmp.size()-1]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        
    }
    return 0;
}