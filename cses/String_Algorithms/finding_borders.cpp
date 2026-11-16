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
    string s; cin >> s;
    int n = sz(s), l = 0, r = 0;
    vector <int> z(n);
    
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) ++z[i];

        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }

    set <int> st;
    for (int i = 0; i < n; ++i) {
        if (z[i] && i + z[i] == n) st.insert(z[i]);
    }

    for (auto &i : st) cout << i << " ";
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

