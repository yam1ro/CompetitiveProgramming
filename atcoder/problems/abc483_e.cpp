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
    vector <string> str(n);
    
    for (auto &i : str) cin >> i;

    unordered_map <string, int> mp;
    int a = 0, b = 0, c = 0;
    
    for (auto &s : str) {
        a += mp[s]++;
    }

    for (int j = 0; j < m; ++j) {
        mp.clear();
        for (auto s : str) {
            s[j] = '*';
            b += mp[s]++;
        }
    }

    for (int l = 0; l < m; ++l) {
        for (int r = l + 1; r < m; ++r) {
            mp.clear();

            for (auto s : str) {
                s[l] = s[r] = '*';
                c += mp[s]++;
            }
        }
    }

    int d0 = a, d1 = b - m * d0, d2 = c - m * (m - 1) / 2 * d0 - (m - 1) * d1;
    cout << d0 + d1 + d2;
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

