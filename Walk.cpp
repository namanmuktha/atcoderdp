#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    const int MOD = 1e9 + 7;
    int cnt = 0;
    for (int start = 0; start < n; start++) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            
            if (dist == k) {
                cnt = (cnt + 1) % MOD;
                continue;
            }
            
            for (int next = 0; next < n; next++) {
                if (v[node][next] == 1) {
                    q.push({next, dist + 1});
                }
            }
        }
    }

    cout << cnt << endl;
    
}
