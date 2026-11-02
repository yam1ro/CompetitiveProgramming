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
    int l = 1e9 + 1;

    auto ask = [&] (int x) {
        cout << "? " << x << endl;
        string s; cin >> s;
        int d; cin >> d;
        pair <int, int> bc;
        bc.F = (s == "YES"), bc.S = d;
        return bc;
    };

    auto dir = [&] (int x, int d, int t) {
        int s = (x + d) % l, f = (x - d + f) % l;
        return (t ? f : s);
    };

    auto pr = [&] (int ans) {
        cout << "! " << ans << endl; 
    };

    map <int, int> used;

    for (int i = 1; i <= 15; ++i) {
        int cur = rand() % l;
        while (used.count(cur)) cur = rand() % l;
        int t = rand() % 2;
        auto [ret, d] = ask(cur);
        int x =  dir(cur, d, t);
        auto [ret2, d2] = ask(x);
        int ans = dir(cur, d, t ^ 1);
        
        if (!ret2) {
            pr(ans);
            return;
        }
        else used[x] = 1;
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

