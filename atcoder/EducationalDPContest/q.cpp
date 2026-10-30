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

struct BIT {
    int n;
    vector <int> t;

    BIT (int _n) : n(_n) {
        t.resize(n + 1);
    };

    void upd(int x, int p) {
        for (int i = p; i <= n; i += i & -i) {
            t[i] = max(t[i], x); 
        }
    }
    
    int get(int r) {
        int ret = 0;
        for (int i = r; i >= 1; i -= i & -i) {
            ret = max(ret, t[i]);
        }
        return ret;
    }
};

void solve() {
   int n; cin >> n;
   vector <int> h(n + 1), a(n + 1);

   for (int i = 1; i <= n; ++i) {
       cin >> h[i];
   }

   for (int i = 1; i <= n; ++i) {
       cin >> a[i];
   }

   BIT bit(n);
   vector <int> dp(n + 1);
   for (int i = 1; i <= n; ++i) {
       dp[i] = bit.get(h[i] - 1) + a[i];
       //cout << bit.get(h[i]) << " ";
       bit.upd(dp[i], h[i]);
   }
   
   cout << bit.get(n);
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

