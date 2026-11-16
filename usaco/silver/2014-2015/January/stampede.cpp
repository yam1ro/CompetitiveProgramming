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

void solve() {
    int n; cin >> n;
    vector <pair <int, int>> seg;

    for (int i = 0; i < n; ++i) {
        int x, y, r; cin >> x >> y >> r;
        int t1 = (-x - 1) * r, t2 = -x * r;

        seg.ph({t1, y}); seg.ph({t2, -y});
    }

    sort(all(seg));

    set <int> cur, was;

    int i = 0, m = sz(seg);
    while (i < m) {
        int curt = seg[i].F;
        int j = i;

        while (j < m && seg[j].F == curt) {
            int y = seg[j].S;
            if (y > 0) cur.insert(y);
            else cur.erase(-y);
            ++j;
        }

        if (!cur.empty()) {
            was.insert(*cur.begin());
        }

        i = j;
    }

    cout << sz(was);
}

signed main() {
  freopen("stampede.in", "r", stdin);
  freopen("stampede.out", "w", stdout);
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

