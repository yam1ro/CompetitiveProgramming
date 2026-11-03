#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ph push_back
#define pp pop_back
#define ar array

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    
    int cnt[3];
    cnt[0] = (r / 3) - (l - 1) / 3, cnt[1] = (r + 2) / 3 - (l + 1) / 3, cnt[2] = (r + 1) / 3 - l / 3;
 
    vector <ar <int, 3> > dp(n + 1);
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][(j + k) % 3] = (dp[i][(j + k) % 3] + dp[i - 1][j] * cnt[k]) % MOD;
            }
        }
    }
 
    cout << dp[n][0];
}

signed main() {
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

