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

struct SegTree {
    int n;
    vector <int> t;

    SegTree(int _n) : n(_n) {
        t.resize((n + 3) << 2, -INF);
    };

    void build(int v, int tl, int tr, vector <int> &a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) >> 1;

        build(v << 1, tl, tm, a); build(v << 1 | 1, tm + 1, tr, a);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    void build(vector <int> &a) {
        build(1, 1, n, a);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return -INF;
        if (tl >= l && tr <= r) return t[v];

        int tm = (tl + tr) >> 1;

        return max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

void solve() {
    int n, h; cin >> n >> h;
    vector <int> a(n + 1), b(n + 1), pf(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
        b[i] = a[i] - i;
    }
     
    SegTree siga(n);
    siga.build(b);
    
    int res = INF;
    for (int l = 1; l + h - 1 <= n; ++l) {
        int r = l + h - 1;
        if (siga.get(l, r) <= 1 - l) {
            int sum = pf[r] - pf[l - 1];
            res = min(res, (h * (h + 1) >> 1) - sum);
        }
    }

    cout << (res == INF ? -1 : res);
}

signed main() {
  freopen("seq.in", "r", stdin);
  freopen("seq.out", "w", stdout);
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

