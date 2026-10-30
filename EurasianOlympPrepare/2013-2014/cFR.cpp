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
    vector <int> p(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        p[i] = i + 1;
    }

    vector <int> ans;
    do {
        for (int i = 0; i < n - 1; ++i) {
            ans.ph(p[i]);
        }
        ans.ph(n);

        for (int i = 0; i < n - 1; ++i) {
            ans.ph(p[i]);
        }
    }
    while (next_permutation(all(p)));

    cout << sz(ans) << "\n";
    for (auto &i : ans) cout << i << " ";
}

signed main() {
freopen("cipher.in", "r", stdin);
freopen("cipher.out", "w", stdout);
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

