#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int srcx,srcy,destx,desty;
vector<pair<int,int> > v;
int n;
int mini=INT_MAX;
int swap(int arr[],int l,int r)
{
    int x=arr[l];
    arr[l]=arr[r];
    arr[r]=x;
}
void permutation(int arr[],int l,int r)
{
	if(l==r)
	{
	    int sum=0;
	    int prex=srcx;
	    int prey=srcy;
	    for(int i=0;i<n;i++)
        {
            //cout<<arr[i]<<" ";
        }
       // cout<<endl;
        for(int i=0;i<n;i++)
        {
            sum+=abs(v[arr[i]].first-prex)+abs(v[arr[i]].second-prey);
            prex=v[arr[i]].first;
            prey=v[arr[i]].second;
        }
       sum+=abs(v[arr[n-1]].first-destx)+abs(v[arr[n-1]].second-desty);
      // cout<<sum<<endl;
       mini=min(mini,sum);

    }
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			swap(arr,l,i);
			permutation(arr,l+1,r);
			swap(arr,l,i);
		}
	}
}
int main()
{
    int t,x,y,i;
    t=10;
    while(t--)
    {
        cin>>n;
        cin>>srcx>>srcy>>destx>>desty;
        v.clear();
        mini=INT_MAX;
        int x,y;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
           v.pb(mp(x,y));
        }
        int arr[15];
        for(i=0;i<=n;i++)
        {
            arr[i]=i;
        }
        permutation(arr,0,n-1);cout<<mini<<endl;
    }
}
