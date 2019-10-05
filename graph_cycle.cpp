#include<bits/stdc++.h>
using namespace std;
int nodes,edges;
vector<int> adj[1000];
vector<int> cycle;
bool visited[1000];
bool flag=false;
void dfs(int initial,int cur)
{
    if(visited[cur] && cur==initial){
        flag=true;
        return;
    }
    if(visited[cur])
        return;
    if(flag)return;
    visited[cur]=true;
    cycle.push_back(cur);
    for(int i=0;i<adj[cur].size();i++){
        if(flag)return;
        dfs(initial,adj[cur][i]);
    }
    if(flag)return;
    cycle.pop_back();
}
int main()
{
    int T,t=1;
    cin>>T;
    while(T--){
        cycle.clear();
        flag=false;
        cin>>nodes>>edges;
        for(int i=0;i<=nodes;i++){
            adj[i].clear();
            visited[i]=false;
        }
        for(int i=0;i<edges;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(int i=1;i<=nodes;i++){
            cycle.clear();
            flag=false;
            dfs(i,i);
            if(flag)break;
            for(int i=1;i<=nodes;i++)visited[i]=false;
        }
        cout<<"#"<<t++<<" ";
        if(!flag)cout<<"0\n";
        else{
            sort(cycle.begin(),cycle.end());
            for(int i=0;i<cycle.size();i++)cout<<cycle[i]<<" ";
            cout<<"\n";
        }
    }
}
