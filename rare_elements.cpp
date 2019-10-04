#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
int N,K;
int res;
struct point elements[6];
int arr[20][20];
int farr[20][20];
int visited[20][20];
int dp[6][20][20];
int row[4]={1,-1,0,0};
int col[4]={0,0,-1,1};
bool chk(int x,int y){
    if(x<0 || y<0 || x>=N || y>=N || visited[x][y]==1 || arr[x][y]==0)
        return(false);
    return(true);
}
void bfs(int num)
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)visited[i][j]=0;
    }
    vector<struct point> q;
    q.insert(q.begin(),elements[num]);
    int x=elements[num].x;
    int y=elements[num].y;
    dp[num][x][y]=0;
    visited[x][y]=1;
    while(q.size()>0){
        int x1=q[q.size()-1].x;
        int y1=q[q.size()-1].y;
        q.pop_back();
        for(int i=0;i<4;i++){
            if(chk(x1+row[i],y1+col[i])){
                point p;
                p.x=x1+row[i];p.y=y1+col[i];
                q.insert(q.begin(),p);
                visited[x1+row[i]][y1+col[i]]=1;
                dp[num][x1+row[i]][y1+col[i]]=1+dp[num][x1][y1];
            }
        }
    }
}
int main()
{
    int T,t=1;
    cin>>T;
    while(T--){
        res=INT_MAX;
        cin>>N>>K;
        for(int i=0;i<K;i++)cin>>elements[i].x>>elements[i].y;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>arr[i][j];
                farr[i][j]=0;
            }
        }
        for(int i=0;i<K;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++)dp[i][j][k]=INT_MAX;
            }
        }
        for(int i=0;i<K;i++){
            bfs(i);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<K;k++){
                    farr[i][j]=max(farr[i][j],dp[k][i][j]);
                }
                if(farr[i][j]<res)res=farr[i][j];
            }
        }
        cout<<"#"<<t<<" "<<res<<"\n";
    }
}
