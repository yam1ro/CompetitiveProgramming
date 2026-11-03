#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ph push_back
#define pb pop_back

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector <pair <int, int> > pts(n + 1);

    auto getDist = [&] (pair <int, int> a, pair <int, int> b) {
        auto [fx, fy] = a;
        auto [sx, sy] = b;

        return (abs(fx - sx) + abs(fy - sy));
    };

    for (int i = 1; i <= n; ++i) {
        cin >> pts[i].F >> pts[i].S;
    }

    vector < vector <int> > dp(n + 1, vector <int> (k + 1, INF));
    
    dp[1][0] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + getDist(pts[i - 1], pts[i]);
    }

    for (int i = 2; i <= n; ++i) {
        for (int p = 0; p < i; ++p) {
            for (int j = 1; j <= k; ++j) {
                int skip = i - p - 1;
                if (j >= skip) {
                    dp[i][j] = min(dp[i][j], dp[p][j - (i - p - 1)] + getDist(pts[p], pts[i]));
                }
            }
        }
    }

    // int res = INF;

    // for (int j = 0; j <= k; ++j) {
    //     res = min(res, dp[n][j]);
    // }

    // cout << res;

    //ofc always is profitable to use all k

    cout << dp[n][k];
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
        cout << "\n";
    }
}