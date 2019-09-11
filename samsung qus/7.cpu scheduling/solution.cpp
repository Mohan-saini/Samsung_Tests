#include<bits/stdc++.h>
using namespace std;
int dp[102][102][102][10][4]; // dp[D][E][F][N][MAX}
int n;
typedef struct shivam
{
    int a,b,c,p;
}shivam;
shivam s[1002];

int D,E,F,d,e;

int fun(int D1,int E1,int F1,int index,int x)
{
    if(x==0||index==0)
    {
        return D1*d+E1*e;
    }
    if(D1==0)
    {
        return E1*e;
    }
    if(E1==0)
    {
        return D1*d;
    }
    if(dp[D1][E1][F1][index][x]!=-1)
    {
        return dp[D1][E1][F1][index][x];
    }
    int i;
    int maxi=0;
    maxi=fun(D1,E1,F1,index-1,x);
    if((D1-s[index].a>=0)&&(E1-s[index].b>=0)&&(F1-s[index].c>=0)){

       //     cout<<"yes:"<<endl;
    maxi=max(max(fun(D1,E1,F1,index-1,x),s[index].p+fun(D1-s[index].a,E1-s[index].b,F1-s[index].c,index-1,x-1)),s[index].p+fun(D1-s[index].a,E1-s[index].b,F1-s[index].c,index,x));
    }

    // cout<<D1<<" "<<E1<<" "<<F1<<" "<<index<<" "<<x<<" "<<maxi<<endl;
   return dp[D1][E1][F1][index][x]=maxi;

}
int main()
{
    int  t;
    cin>>t;
    while(t--)
    {

        cin>>D>>E>>F>>d>>e;
        cin>>n;
        for(int i1=0;i1<=D;i1++)
        {
            for(int i2=0;i2<=E;i2++)
            {
                for(int i3=0;i3<=F;i3++)
                {
                    for(int i4=0;i4<=n;i4++)
                    {
                        for(int i5=0;i5<=3;i5++)
                        {
                            dp[i1][i2][i3][i4][i5]=-1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].a>>s[i].b>>s[i].c>>s[i].p;
        }
        cout<<fun(D,E,F,n,3);
    }

}
