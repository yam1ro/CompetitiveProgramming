#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int n; cin >> n;
    int res = N;

    //0 - 9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1
    //n - k + 10^ki
    for (int k = 0; k < 10; ++k) {
        int x = n - k, mn = N;
        for (int i = 0; i < 10; ++i) {
            int d = x % 10;
            mn = min(mn, ((7 - d) + 10) % 10);
            x /= 10;
        }
        if (mn <= k) {
            cout << k;
            return;
        }
    }
    
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