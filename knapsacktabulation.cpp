#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n,W;
    cin>>n>>W;
    vector<int>w(n);
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
        cin>>p[i];
    }

    vector<vector<ll> >dp(n+1,vector<ll>(W+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            ll nottaken = dp[i-1][j];
            ll taken = -1e9;
            if(w[i-1]<=j){
                taken = dp[i-1][j-w[i-1]]+p[i-1]; 
            }
            dp[i][j] = max(nottaken,taken);
        }
    }
    cout<<dp[n][W]<<endl;
    return 0;
}