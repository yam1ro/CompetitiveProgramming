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
    int n, e; cin >> n >> e;
    vector <vector <int>> g(n + 1);
    vector <pair <int, int> > val(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        int q, d; cin >> q >> d;
        val[i] = {q, i};
        for (int j = 1; j <= d; ++j) {
            int v; cin >> v;
            g[i].ph(v);
        }
    }
    
    vector <vector <int>> dist(n + 1, vector <int> (n + 1));

    auto bfs = [&] (int st) {
        vector <int> d(n + 1, -INF);
        queue <int> q;
        
        q.push(st);
        d[st] = 0;
        
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int to : g[u]) {
                if (d[to] == -INF) {
                    d[to] = d[u] + 1;
                    q.push(to);
                }
            }
        }

        for (int j = 1; j <= n; ++j) {
            dist[st][j] = d[j];
        }
    };
    
    for (int v = 1; v <= n; ++v) {
        bfs(v);
    }

    sort(all(val));

    vector <int> dp(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        auto [q, v] = val[i];

        dp[v] = max(dp[v], q);
        
        for (int j = i + 1; j <= n; ++j) {
            auto [qto, to] = val[j];

            if (dist[v][to] == -INF) continue;

            dp[to] = max(dp[to], dp[v] + qto - dist[v][to] * e);
        }
    }

    int ans = 0;
    for (int v = 1; v <= n; ++v) {
        ans = max(ans, dp[v]);
    }

    cout << ans;
}

signed main() {
  freopen("buffet.in", "r", stdin);
  freopen("buffet.out", "w", stdout);
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

