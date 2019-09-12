//https://www.geeksforgeeks.org/burst-balloon-to-maximize-coins/
#include<bits/stdc++.h>
using namespace std;
int arr[100];
int dp[102][102];
int n;
int solve()
{
    for(int i=1;i<=n;i++){
        for(int left=1;left<=(n-i+1);left++){
            int right=i+left-1;
            for(int last=left;last<=right;last++){
                dp[left][right]=max(dp[left][right],dp[left][last-1]+arr[left-1]*arr[last]*arr[right+1]+dp[last+1][right]);
            }
        }
    }
    return(dp[1][n]);
}
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)dp[i][j]=0;
    }
    arr[0]=arr[n+1]=1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve()<<endl;
}
