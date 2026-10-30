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
    int n, m; cin >> n >> m;
    vector <int> a(n), pf(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pf[i + 1] = pf[i] + a[i];
    }

    map <int, int> cnt;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += cnt[pf[i] % m]; 
        cnt[pf[i] % m]++;
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

