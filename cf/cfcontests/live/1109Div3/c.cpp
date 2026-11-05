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
    int n, x, y; cin >> n >> x >> y;
    vector <int> pos(n + 1), a(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        int d = abs(pos[a[i]] - a[i]);
        if (d % x && d % y && d % gcd(x, y)) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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