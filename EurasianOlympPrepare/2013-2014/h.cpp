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

vector <int> ans;

void solve() {
    int l, r; cin >> l >> r;
    int cnt = upper_bound(all(ans), r) - lower_bound(all(ans), l);
    //for (int x : ans) cout << x << "\n";
    cout << cnt;
}

signed main() {
freopen("pnumbers.in", "r", stdin);
freopen("pnumbers.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  auto ok = [&] (int x) {
      string a = to_string(x - 1);
      string b = to_string(x + 1);

      while (!a.empty() && a.back() == '0') a.pp();
      while (!b.empty() && b.back() == '0') b.pp();

      string c = a, d = b;
      reverse(all(c)), reverse(all(d));

    return a == c && b == d;
  };

  auto add = [&] (int x) {
      if (x <= INF && ok(x)) ans.ph(x);
  };

  for (int x = 1; x <= 9; ++x) add(x);

  for (int x = 1; x <= INF; ) {
      add(x);
      if (x > INF / 10) break;
      x *= 10;
  }

  for (int len = 2; len <= 19; ++len) {
      int m = len - 2, h = (m + 1) >> 1;

      for (int mask = 0; mask < (1 << h); ++mask) {
          string a(m, '0'), b(m, '0');
          string d1 = "02", d2 = "79";
            
          for (int i = 0; i < m; ++i) {
              int j = min(i, m - 1 - i);
              int bit = (mask >> j) & 1;
              a[i] = d1[bit], b[i] = d2[bit];
          }

          add(stoll("2" + a + "1")); add(stoll("8" + b + "9"));
      }
  }

  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  }
}
