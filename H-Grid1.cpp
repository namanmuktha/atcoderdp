#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> v(m, vector<char>(n)); 
    

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '#') {
                dp[i][j] = 0; 
            } else {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1; 
                } else {
                    if(i > 0) {
                        dp[i][j] += dp[i-1][j]; 
                    }
                    if(j > 0) {
                        dp[i][j] += dp[i][j-1]; 
                    }
                }
            }
        }
    }

    
    cout << dp[m-1][n-1] << endl;
    return 0;
}
