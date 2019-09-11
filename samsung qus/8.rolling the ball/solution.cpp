#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100][100];
int dp[100][100];

int fun(int i,int j)
{
	if(i<1||j>n||i>n||j<1||i==-1||j==-1)
	return 0;
	if(dp[i][j]!=INT_MIN)
	return dp[i][j];
 // cout<<i<<" "<<j<<endl;
	int a,b,c,d;
	a=arr[i-1][j];
	b=arr[i][j+1];
	c=arr[i+1][j];
	d=arr[i][j-1];
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	int maxi=1;
	if(a<arr[i][j])
	{
	  //  cout<<"ye";

		maxi=max(1+fun(i-1,j),maxi);
	}
	if(b<arr[i][j])
	{
			maxi=max(1+fun(i,j+1),maxi);
	}
	if(c<arr[i][j])
	{
			maxi=max(1+fun(i+1,j),maxi);
	}
	if(d<arr[i][j])
	{
		maxi=max(1+fun(i,j-1),maxi);
	}

	dp[i][j]=maxi;
	return maxi;
}
int main()
{
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
	   {
	   	cin>>arr[i][j];
	   	dp[i][j]=INT_MIN;
	   }
	}

	arr[0][0]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[0][i]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[n+1][i]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[i][0]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[i][n+1]=INT_MAX;
	int maxi=INT_MIN;


	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			maxi=max(maxi,fun(i,j));
		}
	}
	cout<<maxi<<endl;

}

////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100][100];
int fun(int i,int j)
{
	if(i<1||j>n||i>n||j<1||i==-1||j==-1)
	return 0;
	int a,b,c,d;
	a=arr[i-1][j];
	b=arr[i][j+1];
	c=arr[i+1][j];
	d=arr[i][j-1];

	int r1,c1;
	r1=-1;
	c1=-1;
	int temp=arr[i][j];
	if(a<temp)
	{
		r1=i-1;
		c1=j;
		temp=a;
	}
	if(b<temp)
	{
		r1=i;
		c1=j+1;
		temp=b;
	}
	if(c<temp)
	{
		r1=i+1;
		c1=j;
		temp=c;
	}
	if(d<temp)
	{
		r1=i;
		c1=j-1;
		temp=d;
	}
	if(i==4&&j==3)
	{
	    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	    cout<<r1<<" "<<c1<<endl;
	}
	return 1+fun(r1,c1);



}
int main()
{
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
	   {
	   	cin>>arr[i][j];
	   }
	}

	arr[0][0]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[0][i]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[n+1][i]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[i][0]=INT_MAX;

	for(i=1;i<=n;i++)
	arr[i][n+1]=INT_MAX;
	int maxi=INT_MIN;




	return 0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			maxi=max(maxi,fun(i,j));

		}
	}
	cout<<maxi<<endl;

}
