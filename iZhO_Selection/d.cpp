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
    string s; cin >> s;

    ar <int, 3> cnt = {0, 0, 0};

    int r = n;

    for (int i = n - 1; i >= 0; --i) {
        cnt[s[i] - 'A']++;

        if (min({cnt[0], cnt[1], cnt[2]}) > 0) {
            r = i;
            break;
        }
    }

    cnt = {0, 0, 0};
    ar <int, 3> mid = {0, 0, 0};

    int ans = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'A']++;
        
        if (min({cnt[0], cnt[1], cnt[2]}) == 0) continue;
        
        j = max(j, i + 1);

        while (j < r && min({mid[0], mid[1], mid[2]}) == 0) {
            mid[s[j] - 'A']++;
            ++j;
        }

        if (min({mid[0], mid[1], mid[2]}) > 0) {
            ans += r - j + 1;
        }

        if (i + 1 < j) {
            mid[s[i + 1] - 'A']--;
        }
    }

    cout << ans;
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

