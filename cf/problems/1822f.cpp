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
    int n, k, c; cin >> n >> k >> c;
    vector <vector <int>> t(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        t[u].ph(v); t[v].ph(u);
    }

    auto bfs = [&] (int st) {
        vector <int> d(n + 1, INF);
        queue <int> q;

        d[st] = 0;
        q.push(st);

        int u = st;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            
            for (auto &to : t[v]) {
                if (d[to] == INF) {
                    d[to] = d[v] + 1;
                    q.push(to);

                    if (d[to] > d[u]) {
                        u = to;
                    }
                }
            }
        }

        return make_pair(u, d);
    };

    auto [a, d1] = bfs(1);
    auto [b, da] = bfs(a);
    auto [f, db] = bfs(b);
    
    int ans = 0;
    
    for (int v = 1; v <= n; ++v) {
        ans = max(ans, k * max(da[v], db[v]) - c * d1[v]);
    }

    cout << ans;
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

