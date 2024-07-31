/* 
Welcome to JDoodle!

You can execute code here in 88 languages. Right now you’re in the C++ IDE.

  1. Click the orange Execute button ▶ to execute the sample code below and see how it works.

  2. Want help writing or debugging code? Type a query into JDroid on the right hand side ---------------->

  3. Try the menu buttons on the left. Save your file, share code with friends and open saved projects.

Want to change languages? Try the search bar up the top. 
*/

#include <iostream>
#include <vector>

using namespace std;

int sol(int i,vector<int>&dp,vector<int>&a){
    if(i==0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int c=sol(i-1,dp,a)+abs(a[i]-a[i-1]);
    if(i>1)
    c=min(  c, sol(i-2,dp,a)+abs(a[i]-a[i-2]));
    return dp[i]=c;
    
}
int main() {
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>dp(n,-1);
    sol(a.size()-1,dp,a);
    // for(auto x:dp)
    // cout<<x<<" ";
    cout<<dp[n-1]<<endl;
}