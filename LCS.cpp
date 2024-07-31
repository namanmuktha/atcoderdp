/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   int n=s1.length(),m=s2.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
   string str="";
   int i=s1.length(),j=s2.length();
   while(i>0 && j>0)
   {
       if(s1[i-1]==s2[j-1])
       {
           str+=s1[i-1];
           i--;
           j--;
       }
       else if(dp[i-1][j]>dp[i][j-1])
       {
           i--;
       }
       else
       {
           j--;
       }
   }
   reverse(str.begin(),str.end());
   cout<<str<<endl;
}