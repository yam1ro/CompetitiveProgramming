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
    vector <int> a(n + 1), pf(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    vector <vector <int> > dp(n + 1, vector <int> (n + 1, INF));
    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 <= n; ++l) {
            int r = len + l - 1;
            
            for (int k = l; k < r; ++k) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pf[r] - pf[l - 1]);
            }
        }
    }
    
    cout << dp[1][n];
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

