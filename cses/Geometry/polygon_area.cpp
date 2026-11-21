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
    int ax = 0, ay = 0;

    vector <ar <int, 2>> pts(n);
    for (auto &[x, y] : pts) {
        cin >> x >> y;
        ax += x, ay += y;
    }
    
    ax /= n, ay /= n;
    

    for (auto &[x, y] : pts) {
        x = x - ax, y = y - ay;
    }
     
    sort(all(pts), [&] (ar <int, 2> a, ar <int, 2> b) {
        double x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
        return y1 / x1 < y2 / x2;
    });
    
    for (int i = 1; i < n; ++i) {
            
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

