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
    int n, m; cin >> n >> m;

    vector <vector <char>> a(n, vector <char> (m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        bool ok = 1;
        if (a[i][0] != 'x') continue;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != 'x') ok = 0;
        }
        if (ok) {
            cout << "Faucet " << i + 1;
            return;
        }
    }
    
    for (int j = 0; j < m; ++j) {
        bool ok = 1;
        if (a[0][j] != 'x') continue;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] != 'x') ok = 0;
        }
        if (ok) {
            cout << "Drain " << j + 1;
        }
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

