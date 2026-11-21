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
    int n, q; cin >> n >> q;
    vector <vector <pair <int, int>>> g(n + 1);
    
    for (int i = 1; i <= q; ++i) {
        int t, u, v; cin >> t >> u >> v;
        g[u].ph({v, t});
    }

    vector <int> low(n + 1), tin(n + 1), in_st(n + 1), scc(n + 1);
    stack <int> st;
    int tmr = 0, cnt = 0;

    function <void(int)> dfs = [&] (int v) {
        low[v] = tin[v] = ++tmr;
        in_st[v] = 1;
        st.push(v);

        for (auto &[to, t] : g[v]) {
            if (!tin[to]) {
                dfs(to);
                low[v] = min(low[v], low[to]);
            }
            else if (in_st[to]) low[v] = min(low[v], tin[to]);
        }

        if (low[v] == tin[v]) {
            ++cnt;
            while (1) {
                int u = st.top(); st.pop();
                scc[u] = cnt;    
                in_st[u] = 0;
                if (u == v) break;
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!tin[i]) dfs(i);
    }

    vector <vector <pair <int, int>>> dag(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (auto &[v, t] : g[u]) {
            if (scc[u] == scc[v]) {
                if (t == 1) {
                    cout << "No";
                    return;
                }
            }
            dag[scc[u]].ph({scc[v], t});
        }
    }

    vector <int> dp(cnt + 1, 1);
    for (int u = cnt; u >= 1; --u) {
        for (auto &[v, t] : dag[u]) {
            dp[v] = max(dp[v], dp[u] + t);
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << dp[scc[i]] << " ";
    }
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

