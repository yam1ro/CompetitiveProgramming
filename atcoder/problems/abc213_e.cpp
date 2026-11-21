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

int dx[4] = {0,  1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

int dx2[3] = {0, 0, 1};
int dy2[3] = {-1, 1, -1};
    
void solve() {
    int h, w; cin >> h >> w;
    vector <vector <char>> mat(h, vector <char> (w));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> mat[i][j];
        }
    }
    
    auto ok = [&] (int i, int j) {
        return i >= 0 && j >= 0 && i < h && j < w;
    };

    vector <vector <int>> dp(h, vector <int> (w, INF));
    dp[0][0] = 0;
    
    queue <pair <int, int>> q;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && mat[nx][ny] == '.' && dp[nx][ny] > dp[x][y]) {
                dp[nx][ny] = dp[x][y];
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (mat[i][j] == '#') {
                for (int k = 0; k < 3; ++k) {
                    int nx = i + dx2[k], ny = j + dy2[k];
                    if (ok(nx, ny)) {
                        for (int h = 0; h < 4; ++h) {
                            int chx = nx + dx[h], chy = ny + dy[h];
                            if (ok(chx, chy) && dp[nx][ny] > dp[chx][chy] + 1) {
                                dp[nx][ny] = dp[chx][chy] + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dp[h - 1][w - 1];
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

