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
    int n; cin >> n;
    vector <int> a(n);

    for (auto &i : a) cin >> i;

    int m; cin >> m;
    vector <int> b(m);

    for (auto &i : b) cin >> i;

    vector <vector <int> > dp(n + 1, vector <int> (m + 1)), par(n + 1, vector <int> (m + 1, -1));
    for (int i = 1; i <= n; ++i) {
        int best = 0, pos = 0;
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
             
            if (b[j - 1] < a[i - 1] && dp[i - 1][j] > best) {
                best = dp[i - 1][j];
                pos = j;
            }

            else if (a[i - 1] == b[j - 1] && best + 1 > dp[i][j]) {
                dp[i][j] = best + 1;
                par[i][j] = pos;
            }
        }
    }

    int i = n, j = 0;
    for (int k = 1; k <= m; ++k) {
        if (dp[n][k] > dp[n][j]) {
            j = k;
        }
    }
    
    vector <int> ans;
    while (i > 0 && j > 0) {
        if (par[i][j] != -1) {
            ans.ph(b[j - 1]);
            j = par[i][j];
        }
        --i;
    }

    int sza = sz(ans);
    
    cout << sza << "\n";
    for (int i = sza - 1; i >= 0; --i) {
        cout << ans[i] << " ";
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

