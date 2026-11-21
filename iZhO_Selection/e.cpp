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
    int n, m; cin >> n >> m;
    vector <vector <pair <int, int>>> g(n + 1);
    
    for (int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        g[u].ph({v, c});
    }
    
    vector <int> f(n + 1, -1), vis(n + 1);

    queue <ar <int, 3> > q;
    q.push({1, -1, 0});

    while (!q.empty()) {
        auto [v, c, d] = q.front(); q.pop();
        
        if (v == n) {
            cout << d;
            return;
        }

        if (vis[v] == 2) continue;
        if (vis[v] == 1 && f[v] == c) continue;

        if (vis[v] == 0) f[v] = c;
        vis[v]++;

        for (auto [u, nc] : g[v]) {
            if (nc == c) continue;
            q.push({u, nc, d + 1});
        }
    }
    
    cout << -1;
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

