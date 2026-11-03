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

const int N = 2e5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n; cin >> n;
    vector <int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector <int> mx(n + 1, -INF), dp(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (mx[a[i]] != -INF) dp[i] = max(dp[i], mx[a[i]] + i + 1);
        
        mx[a[i]] = max(mx[a[i]], dp[i - 1] - i);
    }
     
    cout << dp[n];
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

