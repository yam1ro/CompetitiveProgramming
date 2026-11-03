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
const int L = 1e9;

void solve() {
    int n; cin >> n;

    auto ask = [&] (int x) {
        cout << "? " << x << endl;
        string s; cin >> s;
        int d; cin >> d;
        pair <int, int> bc;
        bc.F = (s == "YES"), bc.S = d;
        return bc;
    };

    auto norm = [&] (int x) {
        return (x - 1 + L) % L + 1;
    };
    
    auto pr = [&] (int ans) {
        cout << "! " << ans << endl; 
    };

    if (n <= 15) {
        vector <int> c;
        for (int i = 0; i < 20; ++i) {
            int cur = rng() % L + 1;
            auto [ret, d] = ask(cur);
            int a = norm(cur + d), b = norm(cur - d);
            for (int &x : c) {
                if (x == a) { pr(a); return; }
                else if (x == b) { pr(b); return; }
            }
            c.ph(a);
            if (b != a) c.ph(b);
        }
        return;
    }

    
    for (int i = 1; i <= 15; ++i) {
        int cur = rng() % L + 1; 
        auto [ret, d] = ask(cur);
        int a = norm(cur + d), b = norm(cur - d);
        auto [ret2, d2] = ask(a);
        
        if (!ret2) {
            pr(b);
            return;
        }
    }

    pr(1);
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

