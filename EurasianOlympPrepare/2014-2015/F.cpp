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
    int a, b; cin >> a >> b;
    int g = gcd(a, b), l = lcm(a, b);
    
    vector <int> d1;
    
    auto divs = [&] (int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                int cur = 1;
                while (x % i == 0) {
                    x /= i;
                    cur *= i;
                }
                d1.ph(cur);
            }
        }

        if (x > 1) d1.ph(x);
    };

    divs(a / g); divs(b / g);

    int ans1 = -1, ans2 = -1, diff = INF, n = sz(d1), k = l / g;
    for (int i = 0; i < (1 << n); ++i) {
        int u = 1;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                u *= d1[j];
            }
        }
         
        int v = k / u;
        if (v < u) swap(u, v);
           
        if (v - u < diff) {
            ans1 = u * g, ans2 = v * g, diff = v - u; 
        }
    }

    cout << ans1 << " " << ans2;
}

signed main() {
  freopen("gcm.in", "r", stdin);
  freopen("gcm.out", "w", stdout);
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

