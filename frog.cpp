#include<iostream>
#include<vector>
using namespace std;
int getans(vector<int>&h,int idx,vector<int>&dp,int k){
    if(idx==0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int mini = 1e9;
    for(int j=idx-1;j>=idx-k;j--){
        if(j>=0){
        mini=min(mini,getans(h,j,dp,k)+abs(h[idx]-h[j]));
        }
    }
    return dp[idx]=mini;
}
int main(){
   int n,k;
   cin>>n>>k;
   vector<int>h(n);
   for(int i=0;i<n;i++){
    cin>>h[i];
   }
   vector<int>dp(n,-1);
   cout<<getans(h,n-1,dp,k);
}