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
    vector <vector <int> > t(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        t[u].ph(v); t[v].ph(u);
    }

    vector <ar <int, 2> > dp(n + 1);
    //dp[1][0] = dp[1][1] = 1;

    function <void(int, int)> dfs = [&] (int v, int p) {
        dp[v][0] = dp[v][1] = 1;
        for (int to : t[v]) {
            if (to != p) {
                dfs(to, v);
                dp[v][0] = dp[v][0] * ((dp[to][0] + dp[to][1]) % MOD) % MOD;
                dp[v][1] = dp[v][1] * dp[to][0] % MOD;
            }
        }
    };

    dfs(1, -1);

    cout << (dp[1][0] + dp[1][1]) % MOD;
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

