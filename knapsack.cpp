#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll getans(ll idx, ll W, vector<ll>& w, vector<ll>& p, vector<vector<ll> >& dp) {
    if (idx < 0) {
        return 0;
    }
    if (dp[idx][W] != -1) {
        return dp[idx][W];
    }
    ll nottake = getans(idx - 1, W, w, p, dp);
    ll take = 0;
    if (w[idx] <= W) {
        take = p[idx] + getans(idx - 1, W - w[idx], w, p, dp);
    }
    dp[idx][W] = max(nottake, take);
    return dp[idx][W];
}

int main() {
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> p(n);
    for (ll i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }
    vector<vector<ll> > dp(n, vector<ll>(W + 1, -1));
    cout << getans(n - 1, W, w, p, dp) << endl;
    return 0;
}
