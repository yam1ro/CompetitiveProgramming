#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void sol() {
    int n; cin >> n;
    vector <int> a(n);

    for (auto &i : a) cin >> i;
    
    sort(all(a));

    int res = 0;
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && (a[i] % 2) != (a[j] % 2)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;
}

signed main() {
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        sol();
        cout << "\n";
    }
}