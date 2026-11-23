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

struct BIT {
   int n;
   vector <int> t;

   BIT (int _n) : n(_n) {
        t.resize(n + 1);
   };

   void upd(int r, int x) {
       for (int i = r; i <= n; i += i & -i) {
           t[i] += x;
       }
   }

   int get(int r) {
       int ret = 0;
       for (int i = r; i >= 1; i -= i & -i) {
           ret += t[i];
       }
       return ret;
   }

   int get(int l, int r) {
       return get(r) - get(l - 1);
   }
};

void solve() {
    int n, t; cin >> n >> t;
    vector <int> pf(n + 1);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pf[i + 1] = pf[i] + x;
    }

    vector <int> b = pf;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    
    auto get = [&] (int x) {
        return lower_bound(all(b), x) - b.begin() + 1;
    };

    auto getUp = [&] (int x) {
        return upper_bound(all(b), x) - b.begin();
    };

    BIT bit(sz(b));
    bit.upd(get(0LL), 1);
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i - bit.get(getUp(pf[i] - t));
        bit.upd(get(pf[i]), 1);
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

