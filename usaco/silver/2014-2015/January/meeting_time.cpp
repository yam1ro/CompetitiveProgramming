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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e4, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector <vector <int> > dpB(n + 1, vector <int> (N + 1)), dpE(n + 1, vector <int> (N + 1));
    
    vector <vector <pair <int, int> > > g(n + 1), g2(n + 1); 
    for (int i = 1; i <= m; ++i) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        g[u].ph({v, c}); g2[u].ph({v, d});
    }
    
    function <void(int, int)> dfs = [&] (int v, int cost) {
        dpB[v][cost] = 1;
         
        for (auto [to, c] : g[v]) {
            if (!dpB[to][c + cost]) dfs(to, c + cost);
        }
    };


    function <void(int, int)> dfs2 = [&] (int v, int cost) {
        dpE[v][cost] = 1;
         
        for (auto [to, c] : g2[v]) {
            if (!dpE[to][c + cost]) dfs2(to, c + cost);
        }
    };
    
    dfs(1, 0); 
    dfs2(1, 0);
    
    for (int t = 0; t <= N; ++t) {
        if (dpB[n][t] && dpE[n][t]) {
            cout << t;
            return;
        }
    }

    cout << "IMPOSSIBLE";
}

signed main() {
  freopen("meeting.in", "r", stdin);
  freopen("meeting.out", "w", stdout);
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

