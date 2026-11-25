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

struct SegTree {
    int n;
    vector <pair <int, int>> t;

    SegTree(int _n) : n(_n) {
        t.resize((n + 3) << 2, {INF, 0});
    }

    pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
        return {min(a.F, b.F), max(a.S, b.S)};
    }
    
    void build(int v, int tl, int tr, vector <int> &a) {
        if (tl == tr) {
            if (a[tl] == -1) t[v] = {INF, 0};
            else t[v] = {a[tl], a[tl]};
            return;
        }
    
        int tm = (tl + tr) >> 1;

        build(v << 1, tl, tm, a); build(v << 1 | 1, tm + 1, tr, a);
        
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void build(vector <int> &a) {
        build(1, 1, n, a);
    }

    pair <int, int> get(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return {INF, 0};
        if (tl >= l && tr <= r) return t[v];

        int tm = (tl + tr) >> 1;
        
        auto a = get(v << 1, tl, tm, l, r), b = get(v << 1 | 1, tm + 1, tr, l, r);

        return {min(a.F, b.F), max(a.S, b.S)};
    }

    pair <int, int> get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    void upd(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            if (x == -1) t[v] = {INF, 0};
            else t[v] = {x, x};
            return;
        }

        int tm = (tl + tr) >> 1;

        (i <= tm ? upd(v << 1, tl, tm, i, x) : upd(v << 1 | 1, tm + 1, tr, i, x));
        
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int i, int x) {
        upd(1, 1, n, i, x);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector <int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree siga(n + 1);
    siga.build(a);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            siga.upd(i, x);
        }
        else {
            int l, r; cin >> l >> r;
            auto [mn, mx] = siga.get(l, r);
             
            if (!mx || mn == mx) {
                cout << "Yes\n";
            }
            else cout << "No\n";
        }
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

