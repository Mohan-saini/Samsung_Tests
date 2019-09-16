#include<bits/stdc++.h>
using namespace std;
int visited[1001];
vector<int> temp;
vector<int> adj[1000];
int flag=0;
void dfs(int initial,int cur){
    if(visited[cur]==1 && cur==initial){
        flag=1;
        return;
    }
    if(visited[cur] || flag==1){
        return;
    }
    visited[cur]=1;
    temp.push_back(cur);
    for(int i=0;i<adj[cur].size();i++){
        if(flag==1)return;
        dfs(initial,adj[cur][i]);
    }
    if(flag==1)return;
    temp.pop_back();
}
int main()
{
    int T,test=1;
    cin>>T;
    while(T--){
        int nodes,edges;
        temp.clear();
        cin>>nodes>>edges;
        for(int i=0;i<=nodes;i++){
            adj[i].clear();
            visited[i]=false;
        }
        int u,v;
        for(int i=0;i<edges;i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        flag=0;
        for(int i=1;i<=nodes;i++){
            flag=0;
            temp.clear();
            dfs(i,i);
            if(flag==1){
                sort(temp.begin(),temp.end());
                break;
            }
            for(int j=0;j<=nodes;j++){
                visited[j]=0;
            }
        }
        cout<<"# "<<test<<" ";
        if(flag==0){
            cout<<"0\n";
        }else{
            for(auto z:temp){
                cout<<z<<" ";
            }
            cout<<"\n";
        }test++;
    }
}
