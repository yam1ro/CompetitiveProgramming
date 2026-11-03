#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define F first
#define S second

void solve() {
    int n, m, k; cin >> n >> m >> k;
    
    vector <int> a(n);
    int res = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res += (m / a[i]);
    }

    int cyc = k / m, rem = k % m;
    res = (res * cyc);
    
    for (int i = 0; i < n; ++i) {
        res += (rem / a[i]);
    }

    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
        cout << "\n";
    }
}