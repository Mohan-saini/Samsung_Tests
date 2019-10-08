/*
      Check if given graph is bipartite or not.
      if it is, print all nodes of same color in sorted order
      else print "-1" without quotes.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[102];
bool visited[102];
int nodes,edges;

bool dfs(int cur,int color[]){
        if(visited[cur])return(true);
        visited[cur]=true;
        for(int i=0;i<graph[cur].size();i++){
            int adj=graph[cur][i];
            if(color[adj]==color[cur])return(false);
            color[adj]=(color[cur]==0)?1:0;
            if(dfs(adj,color)==false)return(false);
        }
        return(true);
    }
int main()
{
    int T,t=1;
    cin>>T;
    while(T--){
        cin>>nodes>>edges;
        for(int i=1;i<=nodes;i++){
            graph[i].clear();
            visited[i]=false;
        }
        for(int i=0;i<edges;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        int color[nodes+1];
        for(int i=0;i<=nodes;i++)color[i]=-1;
        bool flag;
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                color[i]=0;
                flag=dfs(i,color);
                if(!flag)break;
            }
        }
        cout<<"#"<<t++<<" ";
        if(!flag)cout<<"-1\n";
        else{
            for(int i=1;i<=nodes;i++){
                if(color[i]==0)cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}
