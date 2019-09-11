#include<bits/stdc++.h>
using namespace std;
int arr[1002][1001];
int visited[1002][1002];
int n,length;
void dfs(int i,int j)
{
   if(visited[i][j]==1||arr[i][j]==0||i<1||j<1||j>n||i>n)
    return ;
    visited[i][j]=1;
    dfs(i,j+1); // mario can move horizontally
    dfs(i,j-1);
    for(int i1=1;i1<=length;i1++)  // vertical move is done by ladder of length (length) (with the ladder of legth 3 we can climb to i-1,i-2,i-3,i+1,i+2,i+3)
    {
        dfs(i-i1,j);
        dfs(i+i1,j);
    }

}
int main()
{
    int j,k,i;
    cin>>n;
    int r,c;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>r>>c;
    for(i=0;i<=n-1;i++) // this i is used to choose ladder of length i (1st time length of ladder is 0 then 1 then 2..)
    {
        for(int i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                visited[i][j]=0;
            }
        }

        length=i;  // here legth is globally and we have fix the ladder length
        dfs(n,1);   // this is the starting point where mario is standing
        if(visited[r][c]==1)  // if we are able to reache point r,c with ladder of length (length) break the loop
        {
            break;
        }
    }
    cout<<length<<endl;


}
