#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define s second;
int farr[200][1002];  // it store the max value of all values(values means shortest ditance from all rare elements)
int arr[100][100];
int visited[100][100];
int dp[10][100][100]; // dp[1][i][j]-> store the sortst distance of point (i,j) from 1st rare element
int x[10],y[10];
int n,k;
int chk(int x,int y)
{
	if(x<1||x>n||y<1||y>n||(visited[x][y]==1)||(arr[x][y]==0))
	return 0;
	return 1;
}
void fun(int num){  // code for bfs
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			visited[i][j]=0;
		}
	}
	queue<pair<int,int> > q;
	int x1=x[num];
	int y1=y[num];
	dp[num][x1][y1]=0;
	q.push(mp(x1,y1));
	visited[x1][y1]=1;
	while(!q.0empty())
	{
		pair<int,int> p=q.front();
		int x=p.first;
		int y=p.s;
		q.pop();
		if(chk(x+1,y)==1)
		{
			q.push(mp(x+1,y));
			visited[x+1][y]=1;
			dp[num][x+1][y]=1+dp[num][x][y];
		}
		if(chk(x-1,y)==1)
		{
			q.push(mp(x-1,y));
			visited[x-1][y]=1;
				dp[num][x-1][y]=1+dp[num][x][y];
		}
		if(chk(x,y-1)==1)
		{
			q.push(mp(x,y-1));
			visited[x][y-1]=1;
				dp[num][x][y-1]=1+dp[num][x][y];
		}
		if(chk(x,y+1)==1)
		{
			q.push(mp(x,y+1));
			visited[x][y+1]=1;
				dp[num][x][y+1]=1+dp[num][x][y];
		}
	}

}
int main()
{

	int i,j;
	int t;
	cin>>t;
	int testcase=1;
	while(t--){
	cin>>n;
	cin>>k;
	for(i=1;i<=k;i++){

	cin>>x[i]>>y[i];
}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>arr[i][j];
			farr[i][j]=0;
		}
	}
	int f;
	for(f=0;f<=k;f++)
	{
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[f][i][j]=INT_MAX;
		}
	}
	}
	for(f=1;f<=k;f++)
	{
		fun(f);   // fr each rare elemts apply bfs
	}


	int mini=INT_MAX;
	int a,b;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			int flg=0;
			for(f=1;f<=k;f++)
			{
				if(dp[f][i][j]==INT_MAX)
				{
					flg=1;
					break;
				}
			}
			for(f=1;f<=k;f++){
				farr[i][j]=max(farr[i][j],dp[f][i][j]);
			}


		   	if(farr[i][j]<mini)
		   	{
		   		mini=farr[i][j];
		   		a=i;
		   		b=j;
            }
		}
	}
	cout<<"#"<<testcase<<" "<<mini<<endl;
	testcase++;
	}
}
