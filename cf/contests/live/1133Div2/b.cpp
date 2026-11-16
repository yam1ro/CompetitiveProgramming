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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n; cin >> n;

    auto ask = [&] (int l, int r) {
        cout << "? " << l << " " << r << endl;
        int ret; cin >> ret;
        return ret;
    };

    auto ans = [&] (int pr) {
        cout << "! " << (pr ? "YES" : "NO") << endl;
    };
    
    int all = ask(1, n);
    if (!all || all == n) {
        ans(0);
        return;
    }
    
    int l = ask(1, 1), r = ask(n, n);
    if (l == 1 && r == 1) {
        ans(1);
        return;
    }
    
    if (l == 1 && !r) {
        int cnt = ask(all + 1, n);
        ans(cnt);
        return;
    }
    
    if (!l && r == 1) {
        ans(1);
        return;
    }

    if (!l && !r) {
        ans(ask(2, n - 1));
        return;
    }
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

