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
    int n, m; cin >> n >> m;
    vector <vector <int> > a(m + 1, vector <int> (n + 1));
    vector <int> row(m + 1), bad(n + 1), sure(n + 1);
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
        cin >> row[i];
        if (!row[i]) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) bad[j] = 1;
            }
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        if (!row[i]) continue;
        int cnt = 0, pos = -1;
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] && !bad[j]) { ++cnt, pos = j; }
        }

        if (cnt == 1) sure[pos] = 1;

        if (!cnt) {
            cout << "Incorrect";
            return;
        }
    }
    
    vector <int> ans1, ans2, ans3;
    for (int j = 1; j <= n; ++j) {
        if (bad[j]) ans1.ph(j);
        else if (sure[j]) ans2.ph(j);
        else ans3.ph(j);
    }
    
    cout << sz(ans1) << " ";
    for (int &x : ans1) cout << x << " ";
    
    cout << "\n" << sz(ans2) << " ";
    for (int &x : ans2) cout << x << " ";

    cout << "\n" << sz(ans3) << " ";
    for (int &x : ans3) cout << x << " ";
}

signed main() {
freopen("disease.in", "r", stdin);
freopen("disease.out", "w", stdin);
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

