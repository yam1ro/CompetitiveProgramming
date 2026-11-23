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
    map <int, int> mp;

    for (int i = 1; i <= n; ++i) {
        int l, r; cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }

    int pf = 0, prx = -1, pri = -1;
    vector <int> ans(n + 1);

    for (auto &[f, s] : mp) {
        pf += s;
        //cout << "lr: " << f << " " << pf << "\n";
        if (prx != -1) {
            ans[pri] += f - prx;
            //cout << "cur: " <<  f - prx << "\n";
        }
        pri = pf, prx = f;
    }
     
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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

