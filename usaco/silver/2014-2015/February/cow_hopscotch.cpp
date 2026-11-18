#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin() x.rend()
#define F first
#define S second
#define ph push_back
#define pp pop_back
#define ar array

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int r, c, k; cin >> r >> c >> k;
    vector <vector <int>> mat(r, vector <int> (c)), dp(r, vector <int> (c));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
            if (!i || !j || i == r - 1 || j == c - 1) dp[i][j] = -INF;
        }
    }
    
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 1; i < r - 1; ++i) {
        for (int j = 1; j < c - 1; ++j) {
            for (int x = 0; x < i; ++x) {
                for (int y = 0; y < j; ++y) {
                    if (mat[i][j] != mat[x][y]) {
                        dp[i][j] += max(0LL, dp[x][y]);
                        dp[i][j] %= MOD;
                    }
                }
            }
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    
    dp[r - 1][c - 1] = 0;
    for (int x = 0; x < c; ++x) {
        for (int y = 0; y < r; ++y) {
            if (x < c - 1 && y < r - 1 && mat[x][y] != mat[r - 1][c - 1]) {
                //cout << "here: " << dp[x][y] << "\n";
                dp[r - 1][c - 1] += max(0LL, dp[x][y]);
                dp[r - 1][c - 1] %= MOD;
            }
        }
    }
    
    cout << dp[r - 1][c - 1];
}

signed main() {
  freopen("hopscotch.in", "r", stdin);
  freopen("hopscotch.out", "w", stdout);
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

