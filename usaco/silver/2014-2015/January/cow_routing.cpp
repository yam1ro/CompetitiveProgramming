#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ph push_back
#define pp pop_back
#define ar array

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3 + 10, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int a, b, n; cin >> a >> b >> n;
    vector <vector <ar <int, 2>>> cost(N, vector <ar <int, 2>> (N, {INF, INF}));
    
    for (int i = 0; i < N; ++i) {
        cost[i][i] = {0, 0};
    }
    
    for (int i = 0; i < n; ++i) {
        int w, k; cin >> w >> k;

        vector <int> rt(k);
        for (int j = 0; j < k; ++j) {
            cin >> rt[j];

            for (int h = 0; h < j; ++h) {
                cost[rt[h]][rt[j]] = min(cost[rt[h]][rt[j]], {w, j - h});
            }
        }
    }


    vector <int> vis(N + 1);
    vector <ar <int, 2>> dist(N, {INF, INF});
    dist[a] = {0, 0};

    for (int i = 0; i < N; ++i) {
        int u = -1;
        for (int j = 0; j < N; ++j) {
            if (!vis[j]) {
                if (u == -1 || dist[u] > dist[j]) u = j;
            }
        }
        
        if (u == -1 || dist[u][0] == INF) break;
        vis[u] = 1;
        
        for (int j = 0; j < N; ++j) {
            ar <int, 2> tmp = dist[u];
            tmp[0] += cost[u][j][0];
            tmp[1] += cost[u][j][1];
            dist[j] = min(dist[j], tmp);
        }
    }

    if (dist[b][1] <= N) {
        cout << dist[b][0] << " " << dist[b][1];
        return;
    }

    cout << "-1 -1";
}

signed main() {
  freopen("cowroute.in", "r", stdin);
  freopen("cowroute.out", "w", stdout);
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

