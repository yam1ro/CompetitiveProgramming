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
    int n, q; cin >> n >> q;
    vector <int> a(31);
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[__builtin_ctz(x)]++;
    }
    
    while (q--) {
        int x; cin >> x;
        int ans = 0, pw = 1;
        for (int i = 30; i >= 0 && x >= 0; --i) {
            int cur = 1 << i, tg = min(x / cur, a[i]);
            ans += tg;
            x -= cur * tg;
        }
    
        cout << (x ? -1 : ans) << "\n";
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

