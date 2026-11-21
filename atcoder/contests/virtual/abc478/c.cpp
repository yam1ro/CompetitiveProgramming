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

const int N = 2e5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector <int> a(n);
   
    for (auto &i : a) cin >> i;

    int mn = INF, prmn = INF, mx = -1, prmx = -1;
    vector <int> mp(N + 1);
    auto add = [&] (int x) {
        mp[x]++;
        if (mn != INF) prmn = mn;
        if (mx != -1) prmx = mx;
        mn = min(mn, x);
        mx = max(mx, x);
    };

    auto del = [&] (int x) {
        if (x == mn) {
            if (mp[x] == 1) mn = prmn;
        }

        if (x == mx) {
            if (mp[x] == 1) mx = prmx;
        }
        
        mp[x]--;
    };
    
    int curmn = INF, curmx = -1;
    auto ok = [&] () {
        return curmn <= mn && mx <= curmx;
    };
    
    int ans = INF, l = 0;
    for (int r = 0; r < n; ++r) {
        add(a[r]);
        curmn = min(curmn, a[r]);
        curmx = max(curmx, a[n - r - 1]);
        
        while (!ok()) {
            del(a[l++]);    
        }

        ans = min(ans, r - l + 1);
    }

    cout << (ans <= k ? "Yes" : "No");
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

