#include<bits/stdc++.h>
using namespace std;
typedef struct shivam
{
    int x,y;
}shivam;
shivam s[10002];
int dp[100][100];
int main()
{
    int i,j,k,n,c;
    int t;
    cin>>t;
    while(t--)
    {
         cin>>n;
         for(i=0;i<=2*n+2;i++)
         {
             for(j=0;j<=2*n+2;j++)
             {
                 if(i!=j)
                 dp[i][j]=INT_MAX;
                 else
                    dp[i][j]=0;
             }
         }
         cin>>s[1].x>>s[1].y>>s[2*n+2].x>>s[2*n+2].y; // input source and destination coordinate
         for(i=1;i<=n;i++)
         {
             cin>>s[2*i].x>>s[2*i].y>>s[2*i+1].x>>s[2*i+1].y>>c;  // for each tunnel i there will be two end 2*i amd 2*i+1
             dp[2*i][2*i+1]=c;
			 dp[2*i+1][2*i]=c;
         }
         for(i=1;i<=2*n+2;i++)
             {
                 for(j=1;j<=2*n+2;j++)
                 {
                     if(i!=j&&dp[i][j]==INT_MAX)
                     {
                         dp[i][j]=abs(s[i].x-s[j].x)+abs(s[i].y-s[j].y); // if we havent calculate distance between two points use this logic
                     }
                 }
             }

         for(k=1;k<=2*n+2;k++)
         {
             for(i=1;i<=2*n+2;i++)
             {
                 for(j=1;j<=2*n+2;j++)
                 {
                     if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX)
                     dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);   // copy for floys warshall loops
                 }
             }
         }

     cout<<dp[1][2*n+2]<<endl;
    }
}
