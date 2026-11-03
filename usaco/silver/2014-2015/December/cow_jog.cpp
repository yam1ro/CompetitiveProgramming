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
    int n, t; cin >> n >> t;

    vector <pair <int, int> > pii(n);

    for (int i = 0; i < n; ++i) {
        cin >> pii[i].F >> pii[i].S;
    }

    int res = 0, lt = INF;

    for (int i = n - 1; i >= 0; --i) {
        auto [x, v] = pii[i];
        int cur = x + v * t;

        if (cur < lt) {
            ++res;
            lt = cur;
        }
    }

    cout << res;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
#endif
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