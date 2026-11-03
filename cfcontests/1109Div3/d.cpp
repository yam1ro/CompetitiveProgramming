#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ph push_back
#define pb pop_back

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> a(n + 1), b(m + 1), pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    sort(all(b));
    
    vector < vector <int> > dp(m + 1, vector <int> (2));

    dp[0][0] = pref[b[1]];
    dp[0][1] = -pref[b[1]];

    for (int i = 1; i < m; ++i) {
        dp[i][0] = pref[b[i + 1]] - pref[b[i]] + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = -(pref[b[i + 1]] - pref[b[i]]) + max(dp[i - 1][0], dp[i - 1][1]);
    }
    
    dp[m][0] = (pref[n] - pref[b[m]]) + max(dp[m - 1][0], dp[m - 1][1]);
    
    cout << dp[m][0];
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

/* more easy sol:

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> a(n + 1), b(m + 1), isb(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        isb[b[i]] = 1;
    }

    sort(all(b));
    
    int res = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (isb[i]) {
            res += llabs(sum);
            sum = 0;
        }
    }

    res += sum;

    cout << res;
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

*/