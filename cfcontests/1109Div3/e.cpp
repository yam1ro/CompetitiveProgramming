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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector <int> pref(n + 1);
    for (int i = 0; i + 1 < n; ++i) {
        pref[i + 1] = pref[i] + (s[i] == s[i + 1]);
    }

    pref[n] = pref[n - 1] + (s[n - 1] == s[n - 2]);
    
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        int x = pref[r - 1] - pref[l - 1];
        cout << (x <= k << 1 ? "YES" : "NO");
        cout << "\n";
    }
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
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