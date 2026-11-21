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
    vector <int> mn, mx;

    SegTree(int _n) : n(_n) {
        mn.resize((n + 3) << 2, INF);
        mx.resize((n + 3) << 2, -1);
    }

    void build(int v, int tl, int tr, vector <int> &a) {
        if (tl == tr) {
            mn[v] = mx[v] = a[tl];
            return;
        }

        int tm = (tl + tr) >> 1;

        build(v << 1, tl, tm, a); build(v << 1 | 1, tm + 1, tr, a);

        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void build(vector <int> &a) {
        build(1, 1, n, a);
    }

    int getMx(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return -1;
        if (tl >= l && tr <= r) return mx[v];
            
        int tm = (tl + tr) >> 1;

        return max(getMx(v << 1, tl, tm, l, r), getMx(v << 1 | 1, tm + 1, tr, l, r));
    };

    int getMn(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return INF;
        if (tl >= l && tr <= r) return mn[v];
            
        int tm = (tl + tr) >> 1;

        return min(getMn(v << 1, tl, tm, l, r), getMn(v << 1 | 1, tm + 1, tr, l, r));
    };
};

void solve() {
    int n, k; cin >> n >> k;
    vector <int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree siga(n);
    siga.build(a);

    vector <bool> pf(n + 2, 1), sf(n + 2, 1);
    
    for (int i = 2; i <= n; ++i) {
        pf[i] = pf[i - 1] && (a[i] >= a[i - 1]);
    }

    for (int i = n - 1; i >= 1; --i) {
        sf[i] = sf[i + 1] && (a[i] <= a[i + 1]);
    }
   

    for (int i = 1; i <= n - k + 1; ++i) {
        int l = i, r = i + k - 1;
        if (!pf[l - 1] || !sf[r + 1]) continue;
        
        int mn = siga.getMn(1, 1, n, l, r), mx = siga.getMx(1, 1, n, l, r);
        
        if (l > 1 && a[l - 1] > mn) continue;
        if (r < n && a[r + 1] < mx) continue;

        cout << "Yes";
        return;
    }

    cout << "No";
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

