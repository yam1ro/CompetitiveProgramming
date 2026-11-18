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

struct Edge {
    int u, v, w;
};

struct DSU {
    int n;
    vector <int> p, sz;
    
    DSU (int _n) : n(_n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(all(p), 0);
    }

    int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }
    
    bool uni(int a, int b) {
        a = get(a), b = get(b);

        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        
        p[b] = a;
        sz[a] += sz[b];
        
        return 1;
    }
};

void solve() {
    int n; cin >> n;
    map <int, int> val;

    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    vector <Edge> edg;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            edg.ph({i, j, val[i] ^ val[j]});
        }
    }

    sort(all(edg), [&] (const auto &x, const auto &y) {
        return x.w > y.w;
    });
    
    DSU dsu(n);
    
    int ans = 0;
    for (auto [u, v, w] : edg) {
        //cout << u << " " << v << " " << w << "\n";
        if (dsu.uni(u, v)) {
            ans += w;
        }
    }

    cout << ans;
}

signed main() {
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);
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

