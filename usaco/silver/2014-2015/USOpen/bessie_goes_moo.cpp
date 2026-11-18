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
    
    int arr[256][7];
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        int x; cin >> x;
        arr[c][(x % 7 + 7) % 7]++;
    }

    int ans = 0;

    for (int b = 0; b < 7; ++b)
    for (int e = 0; e < 7; ++e)
    for (int s = 0; s < 7; ++s)
    for (int i = 0; i < 7; ++i)
    for (int g = 0; g < 7; ++g)
    for (int o = 0; o < 7; ++o)
    for (int m = 0; m < 7; ++m) {
        if (((b + 2 * e + 2 * s + i) * (g + o + e + s) * (m + 2 * o)) % 7 == 0) {
            ans += (arr['B'][b] * arr['E'][e] * arr['S'][s] * arr['I'][i] * arr['G'][g] * arr['O'][o] * arr['M'][m]);
        }
    }
    
    cout << ans;
}

signed main() {
  freopen("bgm.in", "r", stdin);
  freopen("bgm.out", "w", stdout);
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

