#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int> >v(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int> >dp(n,vector<int>(3,-1));
    for(int j=0;j<3;j++){
        dp[0][j]=v[0][j];
    }
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+v[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+v[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+v[i][2];
    }
    int ans = -1e9;
    for(int j=0;j<3;j++){
        ans=max(ans,dp[n-1][j]);
    }
    cout<<ans<<endl;
}