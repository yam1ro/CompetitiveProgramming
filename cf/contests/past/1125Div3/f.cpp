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
    int n; cin >> n;
    vector <int> a(n);
    
    map <int, int> h;
    auto get = [&] (int x) {
        if (!h.count(x)) h[x] = rng();
        return h[x];
    };
    
    auto fact = [&] (int x) {
        int pr = 0;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                int cnt = 0;
                while (x % i == 0) {
                    x /= i;
                    ++cnt;
                }
                if (cnt & 1) pr ^= get(i);
            }
        }
        if (x > 1) pr ^= get(x);
        return pr;
    };


    map <int, int> cnt;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[i] = fact(a[i]);
        cnt[d[i]]++;
    }
    
    int ans = 0;
    int pf = 0;
    for (int i = 0; i < n; ++i) {
        pf ^= d[i]; 
        ans += cnt[pf];
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
