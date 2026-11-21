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
#define pb pop_back

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 998244353, MOD2 = 1e9 + 9, INF = 1e18;

struct SegTree {
  int n;
  vector <array <int, 2> > t;

  SegTree (int _n) : n(_n) {
    t.assign((n + 3) << 2, {0, INF});
  };

  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v][0] = t[v][1] = a[tl];
      return;
    }

    int tm = (tl + tr) >> 1;

    build(v << 1, tl, tm, a); build(v << 1 | 1, tm + 1, tr, a);

    t[v][0] = max(t[v << 1][0], t[v << 1 | 1][0]);
    t[v][1] = min(t[v << 1][1], t[v << 1 | 1][1]);
  }

  void build(vector <int> &a) {
    build(1, 1, n, a);
  }

  int get(int v, int tl, int tr, int l, int r, int tp) {
    if (tl > r || tr < l) return (tp == 1 ? 0 : INF);
    if (tl >= l && tr <= r) return (tp == 1 ? t[v][0] : t[v][1]);

    int tm = (tl + tr) >> 1;
    
    if (tp == 1) return max(get(v << 1, tl, tm, l, r, tp), get(v << 1 | 1, tm + 1, tr, l, r, tp));
    else return min(get(v << 1, tl, tm, l, r, tp), get(v << 1 | 1, tm + 1, tr, l, r, tp));
  }

  int get(int l, int r, int tp) {
    return get(1, 1, n, l, r, tp);
  }

  void upd(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
      t[v][0] = t[v][1] = x;
      return;
    }

    int tm = (tl + tr) >> 1;

    p <= tm ? upd(v << 1, tl, tm, p, x) : upd(v << 1 | 1, tm + 1, tr, p, x);

    t[v][0] = max(t[v << 1][0], t[v << 1 | 1][0]);
    t[v][1] = min(t[v << 1][1], t[v << 1 | 1][1]);
  }

  void upd(int p, int x) {
    upd(1, 1, n, p, x);
  }
};

void solve() {
  int n, q; cin >> n >> q;

  vector <int> a(n + 1);
  map <int, int> mp;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }

  SegTree siga(n);
  siga.build(a);

  while (q--) {
    int l, r; cin >> l >> r;
    int mx = siga.get(l, r, 1), mn = siga.get(l, r, 2);
    // cout << mx << " " << mn << "\n";
    int id1 = mp[mx], id2 = mp[mn];
    mp[mx] = id2, mp[mn] = id1;
    siga.upd(id1, mn); siga.upd(id2, mx);
    // cout << mp[mx] << " " << mp[mn] << "\n"
  }

  vector <int> res(n + 1);

  for (int i = 1; i <= n; ++i) {
    res[mp[a[i]]] = a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
}

signed main() {
#ifdef YAM1RO
  freopen("top.in", "r", stdin);
  freopen("top.out", "w", stdout);
#endif
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
