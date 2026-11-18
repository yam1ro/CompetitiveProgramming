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

const int N = 1e9, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n, b; cin >> n >> b;
    vector <pair <int, int>> pts(n);

    for (auto &[p, s] : pts) cin >> s >> p;

    sort(all(pts));

    int ans = INF, mid = lower_bound(all(pts), make_pair(b, 0LL)) - pts.begin();

    int l = mid - 1, r = mid;
    while (l >= 0 && r < n) {
        auto [pl, sl] = pts[l];
        auto [pr, sr] = pts[r];
        int d = pr - pl;
        if (sl < d) --l;
        else {
            ans = min(ans, max(0LL, d - sr));
            ++r;
        }
     }

    l = mid - 1, r = mid;
    while (l >= 0 && r < n) {
        auto [pl, sl] = pts[l];
        auto [pr, sr] = pts[r];
        int d = pr - pl;
        if (sr < d) ++r;
        else {
            ans = min(ans, max(0LL, d - sl));
            --l;
        }
    }
    
    cout << (ans == INF ? -1 : ans);
}

signed main() {
  freopen("trapped.in", "r", stdin);
  freopen("trapped.out", "w", stdout);
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

