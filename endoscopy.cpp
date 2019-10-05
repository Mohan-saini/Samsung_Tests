#include<bits/stdc++.h>
using namespace std;
int mat[51][51];
int depth[51][51];
int visited[51][51];
int N,M,x,y,L;
struct Node{
    int a,b,d;
    Node(int a1,int b1,int d1){
        a=a1;b=b1;d=d1;
    }
};
bool s1(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<M && visited[i][j]==0 && (mat[i][j]==1 || mat[i][j]==3 || mat[i][j]==6 || mat[i][j]==7))
        return(true);
    return(false);
}
bool s2(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<M && visited[i][j]==0 && (mat[i][j]==1 || mat[i][j]==2 || mat[i][j]==4 || mat[i][j]==7))
        return(true);
    return(false);
}
bool s3(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<M && visited[i][j]==0 && (mat[i][j]==1 || mat[i][j]==3 || mat[i][j]==4 || mat[i][j]==5))
        return(true);
    return(false);
}
bool s4(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<M && visited[i][j]==0 && (mat[i][j]==1 || mat[i][j]==2 || mat[i][j]==6 || mat[i][j]==5))
        return(true);
    return(false);
}
void bfs(int x1,int y1,int d)
{
    vector<Node> q;
    Node temp(x1,y1,d);
    q.insert(q.begin(),temp);
    while(q.size()>0){
        temp=q[q.size()-1];q.pop_back();
        int i=temp.a;
        int j=temp.b;
        int c=temp.d;
        depth[i][j]=min(depth[i][j],c);
        visited[i][j]=1;
        if(mat[i][j]==1 || mat[i][j]==3 || mat[i][j]==6 || mat[i][j]==7){
            if(s3(i,j-1)){
                Node t(i,j-1,c+1);
                q.insert(q.begin(),t);
            }
        }
        if(mat[i][j]==1 || mat[i][j]==3 || mat[i][j]==4 || mat[i][j]==5){
            if(s1(i,j+1)){
                Node t(i,j+1,c+1);
                q.insert(q.begin(),t);
            }
        }
        if(mat[i][j]==1 || mat[i][j]==2 || mat[i][j]==4 || mat[i][j]==7){
            if(s4(i-1,j)){
                Node t(i-1,j,c+1);
                q.insert(q.begin(),t);
            }
        }
        if(mat[i][j]==1 || mat[i][j]==2 || mat[i][j]==6 || mat[i][j]==5){
            if(s2(i+1,j)){
                Node t(i+1,j,c+1);
                q.insert(q.begin(),t);
            }
        }
    }
}
int main()
{
    int T,t=1;
    cin>>T;
    while(T--){
        cin>>N>>M;
        cin>>x>>y;
        cin>>L;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>mat[i][j];
                visited[i][j]=0;
                depth[i][j]=1000;
            }
        }
        if(mat[x][y]!=0)
            bfs(x,y,1);
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(depth[i][j]<=L)cnt++;
            }
        }
        cout<<"#"<<t++<<" "<<cnt<<"\n";
    }
}
