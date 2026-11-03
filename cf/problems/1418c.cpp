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
    int n; cin >> n;
    vector <int> a(n);
    for (auto &i : a) cin >> i;

    vector <ar <int, 2> > dp(n + 1, {INF, INF});
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i]);
        
        if (i + 2 <= n) dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i] + a[i + 1]);
        
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        
        if (i + 2 <= n) dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
    }

    cout << min(dp[n][0], dp[n][1]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);  
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  }
}

