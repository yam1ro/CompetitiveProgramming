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

struct DSU {
    int n;
    vector <int> sz, p;

    DSU(int _n) : n(_n) {
        sz.resize(n + 1, 1);
        p.resize(n + 1);
        iota(all(p), 0);
    }

    int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    void uni(int a, int b) {
        a = get(a), b = get(b);
    
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        
        sz[a] += sz[b];
        p[b] = a;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    DSU dsu(n);

    while (q--) {
        int t; cin >> t;
        int u, v; cin >> u >> v;
        if (!t) dsu.uni(u, v);
        else cout << (dsu.get(u) == dsu.get(v) ? 1 : 0) << "\n";
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
