#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int helper(int i,string &s1,int j,string &s2,vector<vector<int> >&dp){
    if(i<0||j<0){
        return 0;
    }
    if(dp[i+1][j+1]!=-1){
        return dp[i+1][j+1];
    }
    if(s1[i]==s2[j]){
        dp[i+1][j+1]=1+helper(i-1,s1,j-1,s2,dp);
    }
    else dp[i+1][j+1] = max(helper(i-1,s1,j,s2,dp),helper(i,s1,j-1,s2,dp));
    return dp[i+1][j+1];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;   
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
    int temp = helper(n-1,s1,m-1,s2,dp);
    string ans;
    int i=n-1;
    int j=m-1;
    while(i>=0&&j>=0){
        if(s1[i]==s2[j]){
            ans.push_back(s1[i]);
            i--;
            j--;
        }
        else if(i>0&&dp[i][j+1]>dp[i+1][j]){
              i--;
        }
        else{
             j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}