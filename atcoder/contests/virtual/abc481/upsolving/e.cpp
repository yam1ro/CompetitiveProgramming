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
const long double PI = acosl(-1.0L);

int cross(pair <int, int> a, pair <int, int> b) {
    return a.F * b.S - a.S * b.F;
}

int half(pair <int, int> a) {
    if (a.S > 0 || (!a.S && a.F > 0)) return 0;

    return 1;
}

void solve() {
    int n; cin >> n;
    vector <pair <int, int>> a(n);

    for (auto &[x, y] : a) cin >> x >> y;

    sort(all(a), [&] (auto x, auto y) {
        if (half(x) != half(y)) return half(x) < half(y);
        return cross(x, y) > 0;
    });

    for (int i = 0; i < n; ++i) {
        a.ph(a[i]);
    }
    
    int ans = 0, l = 0;
    for (int r = 0; r < 2 * n; ++r) {
        while (l < r && (r - l >= n || cross(a[l], a[r]) <= 0)) ++l;

        ans = max(ans, r - l + 1);
    }
    
    cout << ans;
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

