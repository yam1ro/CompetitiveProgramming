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

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

struct Edge {
    int u, v, w;
};

struct DSU {
    int n;
    vector <int> sz, p;

    DSU (int _n) : n(_n) {
        sz.assign(n + 1, 1);
        p.resize(n + 1);
        iota(all(p), 0);
    }; 
    
    int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    bool uni(int a, int b) {
        a = get(a), b = get(b);
        
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        p[b] = a;

        return 1;
    }

    int cmp() {
        set <int> st;
        for (int v = 1; v <= n; ++v) {
            st.insert(get(v));
        }
        return sz(st);
    }
};

void solve() {
   int n, m, q; cin >> n >> m >> q;
   vector <Edge> edg(m);
   
   for (auto &[u, v, w] : edg) {
       cin >> u >> v >> w;
   }
 
   DSU dsu(n);
    
   sort(all(edg), [&] (const Edge &a, const Edge &b) {
        return a.w < b.w;
   });
 
   vector <int> wts;
   int cost = 0, alsm = 0;
   for (int i = 0; i < m; ++i) {
       auto [u, v, w] = edg[i];
       alsm += w;
       if (dsu.uni(u, v)) {
           cost += w;
           wts.ph(w);
       }
   }
   
   int cnt = dsu.cmp();
   //cout << cnt;
 
   reverse(all(wts));
   
   int k = sz(wts);
   vector <int> pf(k + 1, 0);
   for (int i = 0; i < k; ++i) {
       pf[i + 1] = pf[i] + wts[i];
   }
 
   auto f = [&] (int x, int k) {
        return x * (k * (k + 1) >> 1);
   };
   
   auto bs = [&] (int x) {
        int l = 0, r = k + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (wts[m - 1] > x * (cnt - 1 + m)) l = m;
            else r = m;
        }
        return l;
   };
    
   while (q--) {
       int x; cin >> x;
       int k = bs(x);
       //cout << k << " " << pf[k] << "\n";
       cout << alsm - cost + pf[k] - f(x, cnt - 1 + k) << " ";
   }

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
