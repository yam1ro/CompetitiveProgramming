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

struct node {
    int x, y, r;
};

void solve() {
    int n; cin >> n; 

    vector <node> cow(n);
    for (int i = 1; i <= n; ++i) {
        cin >> cow[i].x >> cow[i].y >> cow[i].r;
    }

    vector <pair <int, int> > invs(n);

    for (int i = 0; i < n; ++i) {
        int r = abs(cow[i].x) * cow[i].r;
        int l = r - cow[i].r;
        invs[i] = {l, r}; 
    }

    sort(all(cow), [&] (const node a, const node b) {
        return a.y < b.y; 
    });

    int res = 0;

    for (int i = 0; i < n; ++i) {
        
    }
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("stampede.in", "r", stdin);
	freopen("stampede.out", "w", stdout);
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