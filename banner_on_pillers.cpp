#include<iostream>
using namespace std;
int dp[1005][1005];
int dp1[1005][1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		for(int i=0;i<=1000;i++){
			for(int j=0;j<=1000;j++)
				dp[i][j]=0;
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=1000;j++){
				for(int k=0;k<=1000;k++){
					if(j>=arr[i]){
						if(dp[j-arr[i]][k]){
							dp1[j][k]=1;
						}
					}
					if(k>=arr[i]){
						if(dp[j][k-arr[i]]){
							dp1[j][k]=1;
						}
					}
					if(dp[j][k]){
						dp1[j][k]=1;
					}
				}
			}
			for(int j=0;j<=1000;j++){
				for(int k=0;k<=1000;k++){
					dp[j][k]=dp1[j][k];
					dp1[j][k]=0;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=1000;i++){
			if(dp[i][i]){
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
}
