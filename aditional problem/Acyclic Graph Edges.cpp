#include<bits/stdc++.h>
using namespace std;
/*
vector<int> a[100010];
bool visited[100010];
stack<int> answer;
void dfs(int now,int deep){
    for(int i=0;i<a[now].size();i++){
        int next=a[now][i];
        visited[next]=true;
        answer.push_back(next);
        dfs(next);
        visited[next]=false;
        answer.push_back(next);
    }
    return;
}
*/
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        int A,B;
        cin>>A>>B;
        if(i){
            cout<<A<<" "<<B<<endl;
        }else{
            a=A;
            b=B;
        }
        //a[A].push_back(B);
        //a[B].push_back(A);
    }
    cout<<a<<" "<<b;
    //visited[1]=true;
    //answer.push_back(1);
    //dfs(1,1);
    return 0;
}
