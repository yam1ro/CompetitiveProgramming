#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ph push_back
#define pp pop_back
#define ar array

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n; cin >> n;
    vector <int> c(n + 1);
    vector <string> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        reverse(all(b[i]));
    }
    
    vector <ar <int, 2>> dp(n + 1, {INF, INF});
    dp[1][0] = 0;
    dp[1][1] = c[1];

    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] <= a[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (b[i - 1] <= a[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (a[i - 1] <= b[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (b[i - 1] <= b[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    
    int ans = min(dp[n][0], dp[n][1]);
    cout << (ans == INF ? -1 : ans);
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

