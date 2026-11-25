#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ph push_back
#define pp pop_back
#define ar array

template <class T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 5, P = 911382, P2 = 972663, MOD = 1e9 + 7, MOD2 = 998244353, INF = 1e18;

void solve() {
    int n; cin >> n;
    vector <vector <int>> t(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        t[u].ph(v); t[v].ph(u);
    }
    
    vector <int> c(n + 1);
    for (int v = 1; v <= n; ++v) {
        cin >> c[v];
    }
    
    auto bfs = [&] (int st) {
        vector <int> d(n + 1, INF);
        queue <int> q;
        
        d[st] = 0;
        q.push(st);

        int mx = 0, u = st;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            
            for (auto to : t[v]) {
                if (d[to] == INF) {
                    d[to] = d[v] + 1;
                    if (d[to] > mx) {
                        mx = d[to];
                        u = to;
                    }
                    q.push(to);
                }
            }
        }
        pair <int, vector <int>> tmp = {u, d};
        return tmp;
    };

    auto [f, d1] = bfs(1);
    auto [s, d] = bfs(f);
    
    int k = d[s] >> 1;
    //cout << "d: " << d[s] << " k: " << k << " s: " << s << "\n";
    
    vector <int> path;
    int v = s;
    while (v != f) {
        path.ph(v);
        for (auto to : t[v]) {
            if (d[to] == d[v] - 1) {
                v = to;
                break;
            }
        }
    }
        
    path.ph(f);
        
    int st = path[k];
    
    if (d[s] & 1) {
        vector <int> colL(n + 1), colR(n + 1), dep(n + 1);
         
        int st = path[k], en = path[k + 1];

        function <void(int, int, vector <int>&)> dfs = [&] (int v, int p, vector <int> &col) {
            if (dep[v] == k) col[c[v]]++;

            for (auto to : t[v]) {
                if (to == p) continue;
                
                dep[to] = dep[v] + 1;
                dfs(to, v, col);
            }
        };
        
        
        dep[st] = 0;
        dfs(st, en, colL);
        
        dep[en] = 0;
        dfs(en, st, colR);

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += colL[i] * colR[i];
        }

        cout << ans;
    }
    else { 
        vector <int> cnt(n + 1), col;
        
        //cout << st << " " << en << "\n\n\n\n";

        function <void(int, int, int)> dfs = [&] (int v, int p, int dep) {
            if (dep == k) {
                col.ph({c[v]});
                return;
            }
            
            for (auto to : t[v]) {
                if (to == p) continue;
                
                dfs(to, v, dep + 1);
            }
        };
        
        int ans = 0;
        for (auto to : t[st]) {
            col.clear();

            dfs(to, st, 1);

            for (auto &x : col) ans += cnt[x];
            for (auto &x : col) cnt[x]++;
        }

        cout << ans;
    } 
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

