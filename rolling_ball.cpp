/*
  you are given a 2D matrix. from a coordinate(i,j) we can go to any of 4
  adjecent point (only 4 direction) if value at that adjecent cell has less value
  than the value of (i,j). so possible we can move to all 4 direction or may be none
  of direction. so you can start from any coordinate. you need to find 
  maximum distance you can travel.
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int dp[100][100];
int n;
int solve(int r,int c)
{
    if(r<1 || c<1||r>n||c>n)return(0);
    if(dp[r][c]!=INT_MIN)return(dp[r][c]);
    int A,B,C,D;
    A=arr[r-1][c];
    B=arr[r+1][c];
    C=arr[r][c-1];
    D=arr[r][c+1];
    int maxi=1;
    if(A<arr[r][c]){
        maxi=max(1+solve(r-1,c),maxi);
    }
    if(B<arr[r][c]){
        maxi=max(1+solve(r+1,c),maxi);
    }
    if(C<arr[r][c]){
        maxi=max(1+solve(r,c-1),maxi);
    }
    if(D<arr[r][c]){
        maxi=max(maxi,1+solve(r,c+1));
    }
    return (dp[r][c]=maxi);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            dp[i][j]=INT_MIN;
        }
    }
    arr[0][0]=INT_MAX;
    for(int i=1;i<=n;i++)arr[0][i]=INT_MAX;
    for(int i=1;i<=n;i++)arr[i][0]=INT_MAX;
    for(int i=1;i<=n;i++)arr[n+1][i]=INT_MAX;
    for(int i=1;i<=n;i++)arr[i][n+1]=INT_MAX;
    int maxi=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maxi=max(maxi,solve(i,j));
        }
    }
    cout<<maxi<<"\n";
}
