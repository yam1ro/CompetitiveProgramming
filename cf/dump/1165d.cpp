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
    vector <int> d(n);
    
    for (auto &i : d) cin >> i;

    sort(all(d));
    int ans = d[0] * d[n - 1];

    vector <int> d2;
    for (int i = 2; i * i <= ans; ++i) {
        if (ans % i == 0) {
            d2.ph(i);
            if (i * i != ans) d2.ph(ans / i);
        }
    }
    
    sort(all(d2));

    cout << (d == d2 ? ans : -1);
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

