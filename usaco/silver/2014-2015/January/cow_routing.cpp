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
    int u, v, w;
};

void solve() {
    int a, b, n; cin >> a >> b >> n;
    vector < vector <node> > g((n << 1)+ 1);
        
    for (int i = 1; i <= n << 1; ++i) {
        int c, m; cin >> c >> m;
        int lt; cin >> lt;
        for (int j = 2; j <= m; ++j) {
            int vr; cin >> vr;

            if (lt == vr) continue;

            g[lt].push_back({lt, vr, c});
            lt = vr;
        }
    }

    for (int i = 1; i <= n << 1; ++i) {
        if (g[i].empty()) continue;
        for (auto [u, v, w] : g[i]) {
            cout << u << " " << v << " " << w << "\n";
        }
    }

    auto Dijkstra = [&] (int st) {
        vector <int> dist(n + 1);
        dist[st] = 0;
        
        queue <int> q;
        q.push(st);

        while (q.empty()) {
            int cvrt = q.front();

            for (auto [u, v, w] : g[cvrt]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    
                }
            } 
        }
    };
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
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