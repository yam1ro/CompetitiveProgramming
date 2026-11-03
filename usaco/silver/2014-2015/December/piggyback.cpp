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
    vector <int> dist, path;
};

void solve() {
    int B, E, P, n, m; cin >> B >> E >> P >> n >> m;

    vector <vector <int> > g(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&] (int st) {
        vector <int> dist(n + 1, -1), par(n + 1, -1);
        queue <int> q;
        dist[st] = 0;
        q.push(st);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    par[to] = v;
                    q.push(to);
                }
            }
        }

        vector <int> path;
        for (int cur = n; cur != -1; cur = par[cur]) {
            path.push_back(cur);
        }

        reverse(all(path));

        node nd;

        nd.dist = dist, nd.path = path;

        return nd;
    };

    auto [besDist, besPath] = bfs(1);
    auto [elzDist, elzPath] = bfs(2);
    
    // for (auto &v : besPath) {
    //     cout << v << " " << besDist[v] << "\n";
    // }

    // cout << "\n";

    // for (auto &v : elzPath) {
    //     cout << v << " " << elzDist[v] << "\n";
    // }

    int res = INF;
    for (auto &v : besPath) {
        res = min(res, elzDist[v] * E + besDist[v] * B + (besDist[n] - besDist[v]) * P);
    }

    for (auto &v : elzPath) {
        res = min(res, besDist[v] * B + elzDist[v] * E + (elzDist[n] - elzDist[v]) * P);
    }

    cout << res;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
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