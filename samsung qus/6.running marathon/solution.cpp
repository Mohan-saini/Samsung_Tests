#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
vector<pair<int,pair<int,int> > >v;
int dp[1002][1002];
int fun(int energy,int distance)
{
    if(dp[energy][distance]!=-1)
        return dp[energy][distance];
    if(distance!=0&&energy==0)
        return INT_MAX;
    if(distance==0)
        return 0;

    int i;
    int mini=INT_MAX;
    for(i=0;i<=4;i++)
    {
        if((energy-v[i].first>=0)&&(fun(energy-v[i].first,distance-1)!=INT_MAX))
      mini=min(mini,v[i].second.first*60+v[i].second.second+fun(energy-v[i].first,distance-1));
    }
    return dp[energy][distance]=mini;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,k;
        v.clear();
        for(i=0;i<=1000;i++)
        {
            for(j=0;j<=1000;j++)
            {
                dp[i][j]=-1;
            }
        }
        int e,d;
        cin>>e>>d;
        for(i=0;i<5;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v.pb(mp(c,mp(a,b)));
        }
        cout<<fun(e,d)<<endl;

    }

}
