// author: yam1ro

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int m, s; cin >> m >> s;
    if (!s) {
        if (m == 1) cout << "0 0";
        else cout << "-1 -1";
        return;
    }
    if (s > m * 9) {
        cout << "-1 -1";
        return;
    }

    auto ch = [&] (int ss, int len) {
        return (ss >= 0 && len * 9 >= ss);
    };

    string a = "";
    int sum = s;
    for (int i = 1; i <= m; ++i) {
        for (int d = 0; d <= 9; ++d) {
            if ((i > 1 || d > 0 || (m == 1 && d == 0)) && ch(sum - d, m - i)) {
                a += (char)(d + '0');
                sum -= d;
                break;
            }
        }
    }

    string b = "";
    sum = s;
    for (int i = 1; i <= m; ++i) {
        for (int d = 9; d >= 0; --d) {
            if ((i > 1 || d > 0 || (m == 1 && d == 0)) && ch(sum - d, m - i)) {
                b += (char)(d + '0');
                sum -= d;
                break;
            }
        }
    }
    
    cout << a << " " << b;
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