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
    vector <int> a(n);

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    vector <int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    set <vector <int> > b;
    
    do {
        b.insert(a);
    }
    while (next_permutation(all(a)));
    

    auto ok = [] (vector <int> f, vector <int> s) {
        for (int j = 0; j < sz(f); ++j) {
            if (f[j] != s[j]) return 0;
        }
        return 1;
    };
    
    vector <int> ans;
    
    vector <int> cur = *b.begin();
    while (!b.empty()) { 
        for (int len = n - 1; len >= 0; --len) {
            vector <int> suff;
            for (int k = n - len; k < n; ++k) {
                suff.ph(cur[k]);
            }
            for (auto &v : b) {
                if (ok(suff, v)) {
                    for (int j = sz(suff); j < n; ++j) {
                    ans.ph(v[j]);
                    }
                    b.erase(b.find(v));
                    cur.clear();
                    int k = sz(ans);
                    for (int j = k - n; j < k; ++j) {
                        cur.ph(ans[j]);
                    }
                }
            }
        }
    }
    
    cout << sz(ans) << "\n";
    for (int &x : ans) cout << x << " ";
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

