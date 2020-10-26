#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll llinf = (1ll << 61) - 1;
const char lf = '\n', splf[] = " \n";
#define sz(a) int(a.size())

#define ceili(a,b) (((a)-1)/(b)+1)
const int inf = 1000000007, N = 200005;
int TC = 1, CN, n, a[N], cl[N], p[N];
ll sa[N], ans;
list<int> g[N];

void dfs(int u) {
    bool leaf = 1;
    for (int &v : g[u]) dfs(v), leaf = 0, sa[u] += sa[v], cl[u] += cl[v];
    sa[u] += a[u], cl[u] += leaf;
    ans = max(ans, sa[u] ? ceili(sa[u], cl[u]) : 0);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout.precision(11), cout.setf(ios::fixed);
    auto kase = [&]() -> void {
        cin >> n;
        for (int i = 2; i <= n; ++i) cin >> p[i], g[p[i]].push_back(i);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        dfs(1);
        cout << ans << lf;
    };
    while (CN++ != TC) kase();
}
