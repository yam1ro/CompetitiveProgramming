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
    int k; cin >> k;
    string t; cin >> t;
    
    auto cnt = [&] (int n, int i) {
        return (i + 1) * (n - i);
    };
    
    auto f = [&] (string s) {
        int ret = 0;
        int n = sz(s);
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            ret += x * cnt(n, i);
        }
        return ret;
    };
     
    auto rep = [&] (int cur) {
        int mn = cur;
        while (1) {
            int nxt = f(to_string(cur));
            mn = min(mn, nxt);
            if (nxt == cur) break;
            cur = nxt;
        }
        return mn;
    }; 

    int sum = f(t);
    cout << rep(sum) << " ";
     
    int q; cin >> q;
    vector <int> p(q), d(q);
    
    for (auto &i : p) cin >> i;
       
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
        int pos = p[i] - 1, old = t[pos] - '0';
        sum -= old * cnt(sz(t), pos);
        sum += d[i] * cnt(sz(t), pos);
        t[pos] = d[i] + '0';
        cout << rep(sum) << " ";
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
