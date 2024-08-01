#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double>c(n);

    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    
    vector<vector<double> >dp(n+1,vector<double>(n+1,0));
    dp[0][0] = 1.00;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
              if(j==0){
                dp[i][j] = dp[i-1][j]*(1-c[i-1]);
              }
              else{
                dp[i][j]=dp[i-1][j]*(1-c[i-1])+dp[i-1][j-1]*c[i-1];
              }
        }
    }
    double ans=0;
    for(int j=n;j>n/2;j--){
        ans+=dp[n][j];
    }
//    cout<<ans<<endl;
 cout << fixed << setprecision(12) << ans << endl;

    return  0;
}