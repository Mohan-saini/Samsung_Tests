#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int k,sum=0,level=-1;
    cin>>k;
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            level++;
        else if(s[i]==')')
            level--;
        else if(level==k){
            int x=s[i]-'0';
            i++;
            while(s[i]>=48 && s[i]<=57){
                int d=s[i]-'0';
                x=x*10+d;
                i++;
            }
            i--;
            sum+=x;
        }
    }
    cout<<sum<<endl;
}
