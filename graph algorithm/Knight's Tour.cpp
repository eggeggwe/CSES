#include <bits/stdc++.h>
using namespace std;
pair<int,int> use[8]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int answer[8][8];
int find_path(int x,int y){
    int tmp=0;
    for(int i=0;i<8;i++){
        if(x+use[i].first<0 || x+use[i].first>=8)continue;
        if(y+use[i].second<0 || y+use[i].second>=8)continue;
        if(answer[x+use[i].first][y+use[i].second]!=0)continue;
        tmp++;
    }
    return tmp;
}
void rec(int x,int y,int deep){
    answer[x][y]=deep;
    if(deep==63){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(j)cout<<" ";
                if(answer[j][i]==0)cout<<64;
                else cout<<answer[j][i];
            }
            cout<<endl;
        }
        exit(0);
    }
    vector<pair<int,int> > tmp;
    for(int i=0;i<8;i++){
        if(x+use[i].first<0 || x+use[i].first>=8)continue;
        if(y+use[i].second<0 || y+use[i].second>=8)continue;
        if(answer[x+use[i].first][y+use[i].second]!=0)continue;
        tmp.push_back(make_pair(find_path(x+use[i].first,y+use[i].second),i));
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++){
        int num,mov;
        tie(num,mov)=tmp[i];
        if(num==0)continue;
        if(answer[x+use[mov].first][y+use[mov].second]!=0)continue;
        rec(x+use[mov].first,y+use[mov].second,deep+1);
    }
    answer[x][y]=0;
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int x,y;
    cin>>x>>y;
    rec(x-1,y-1,1);
    
    return 0;
}