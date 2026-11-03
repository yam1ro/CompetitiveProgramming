#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define F first
#define S second

pair <int, int> egcd(int a, int b) {
    if (!b) return {1, 0};

    auto [nx, ny] = egcd(b, a % b);
    int x = ny, y = nx - (a / b) * ny;

    return {x, y};
}

void solve() {
    int a, b; cin >> a >> b;
    auto [x, y] = egcd(a, b);
    cout << x << " " << y;
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