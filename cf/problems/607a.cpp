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

const int N = 1e6, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n; cin >> n;
    map <int, int> pts;

    for (int i = 0; i < n; ++i) {
        int x, b; cin >> x >> b;
        pts[x] = b;
    }
   
    int mx = 0;
    vector <int> dp(N + 1);
    for (int i = 0; i <= N; ++i) {
        if (!i) dp[i] = (pts[i] ? 1 : 0);
        else {
            if (pts.count(i)) {
                int d = i - pts[i] - 1;
                if (d < 0) dp[i] = max(dp[i], 1LL);
                else dp[i] = max(dp[i], dp[d] + 1);
            }
            else dp[i] = dp[i - 1];
        }
        mx = max(mx, dp[i]);
    }
     
    cout << n - mx;
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

