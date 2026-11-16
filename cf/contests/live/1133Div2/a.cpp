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
    int n, k; cin >> n >> k;
    vector <int> a(n), b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = b[i] % 2;
        if (b[i]) cnt1++;
        a[i] = a[i] % 2;
        if (a[i]) cnt2++;
    }

    if (cnt1 == cnt2) {
        cout << "YES";
        return;
    }

    if (cnt2 > cnt1) {
        for (int i = 0; i < n; ++i) {
            if (((a[i] << 1) + k) % 2 == 0) { a[i] = 0; --cnt2; };
            if (cnt1 == cnt2) {
                cout << "YES";
                return;
            }
        }
    }
    
    if (cnt1 > cnt2) {
        for (int i = 0; i < n; ++i) {
            if (((a[i] << 1) + k) & 1) { a[i] = 1; ++cnt2; };
            if (cnt1 == cnt2) {
                cout << "YES";
                return;
            }
        }
    }
    
    cout << "NO";
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

