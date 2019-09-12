#include<iostream>
using namespace std;
int m,n,k;
int find(int i,int count,int a[100][100],int col[])
{
	if(count==k)
	{
		int dp[100][100];
		for(int l=0;l<n;l++)
		for(int q=0;q<m;q++)
		{
			dp[l][q]=a[l][q];
		}
		for(int w=0;w<k;w++)
		{
			for(int l=0;l<n;l++)
			{
				if(dp[l][col[w]]==0)
				dp[l][col[w]]=1;
				else
				dp[l][col[w]]=0;
			}
		}
		int fact=0,p;
		for(int l=0;l<n;l++)
		{
			for(p=0;p<m;p++)
			{
				if(dp[l][p]!=1)
				break;
			}
			if(p==m)
			{
				fact++;

			}
		}
		return fact;
	}
	col[count]=i;
	int factor,max=INT_MIN;
	for(int j=0;j<m;j++)
	{
		factor=find(j,count+1,a,col);

		if(factor>max)
		max=factor;
	}
	return max;
}
int main()
{
	cin>>n>>m>>k;
	int a[100][100];
	int col[k];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	int max=INT_MIN,factor;
	for(int i=0;i<m;i++)
	{
		factor=find(i,0,a,col);
		if(factor>max)
		max=factor;
	}
	cout<<max;
	return 0;
}
