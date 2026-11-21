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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;
    vector <int> a(n), b(m);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    sort(all(a)); sort(all(b));

    vector <int> pf(n + 1);
    for (int i = 0; i < n; ++i) {
        pf[i + 1] = pf[i] + a[i];
    }

    int sum = x + y * k;
    int ans = 0, w = 0, cnt = 0;
    for (int i = 0; i <= m; ++i) {
        if (i) {
            w += b[i - 1];
            cnt += (b[i - 1] + k - 1) / k;
        }

        if (cnt > y) break;

        int rm = sum - w;
        int cnt = upper_bound(all(pf), rm) - pf.begin() - 1;

        ans = max(ans, i + cnt);
    }

    cout << ans;
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

