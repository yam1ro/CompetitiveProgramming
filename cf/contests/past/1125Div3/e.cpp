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

void solve() {
    int n; cin >> n;
    vector <int> a(n), b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    auto cnt = [&] (int f, int s) {
        return (f == s) + 1;
    };

    int cur = cnt(a[n - 1], b[n - 1]);
    
    for (int i = 0; i + 1 < n; ++i) {
        cur += cnt(a[i + 1], b[i]);
        cur += cnt(a[i], b[i + 1]);
    }

    int ans = cur;

    for (int i = 0; i + 1 < n; ++i) {
        cur -= cnt(a[i], b[i + 1]);
        cur += cnt(a[i], b[i]);
        ans = max(ans, cur);
    }

    cout << ans;
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
