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

struct node {
    int sum, pf;
};

struct SegTree {
    int n;
    vector <node> t;

    SegTree (int _n) : n(_n) {
        t.resize((n + 3) << 2);
    }

    node merge(node a, node b) {
        return {a.sum + b.sum, min(a.pf, a.sum + b.pf)};
    }

    void build(int v, int tl, int tr, vector <int> &a) {
        if (tl == tr) {
            t[v] = {a[tl], a[tl]};
            return;
        }
        
        int tm = (tl + tr) >> 1;

        build(v << 1, tl, tm, a); build(v << 1 | 1, tm + 1, tr, a);
    
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void build(vector <int> &a) {
        build(1, 1, n, a);
    }

    void upd(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, x};
            return;
        }
        
        int tm = (tl + tr) >> 1;

       (i <= tm ? upd(v << 1, tl, tm, i, x) : upd(v << 1 | 1, tm + 1, tr, i, x));
    
       t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int i, int x) {
        upd(1, 1, n, i, x);
    }

    node get(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return {0, INF};
        if (tl >= l && tr <= r) return t[v];
        
        int tm = (tl + tr) >> 1;
        
        return merge(get(v << 0, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r).pf;
    }
};

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i - 1] == 'A' ? 1 : -1);
    }
    
    SegTree siga(n);
    siga.build(a);
    
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c;
            int x = (c == 'A' ? 1 : -1);
            siga.upd(i, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << (siga.get(l, r) >= 0 ? "Yes" : "No") << "\n";
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

