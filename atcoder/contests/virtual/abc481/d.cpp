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
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector <vector <int>> g(n + 1);
    vector <int> mn(n + 1, INF);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].ph(v);
        mn[u] = min(mn[u], v);
    }
   
    vector <int> dp(n + 1, INF);
    deque <int> dq;
    dq.push_front(s);
    dp[s] = 0;

    while (!dq.empty()) {
        int v = dq.front(); dq.pop_front();
        
        for (auto &to : g[v]) {
            int w = (!(to == mn[v]));
            if (dp[v] + w < dp[to]) {
                dp[to] = dp[v] + w;
                if (!w) dq.push_front(to);
                else dq.ph(to);
            }
        }
    }

    cout << (dp[t] == INF ? -1 : dp[t]);
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

