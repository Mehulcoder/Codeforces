/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 7;

ll m, n, k;
vvll edges;
vll govList;
vector<bool> isGov;
vector<bool> visited;

ll dfs(ll root) {
        visited[root] = 1;
        ll ans = 1;
        trav(child, edges[root]) {
                if (!visited[child]) {
                        ans += dfs(child);
                }
        }

        return ans;
}

void solve() {
        cin >> n >> m >> k;
        vset(edges, n, vll(0));
        vset(isGov, 10005, 0);
        govList.clear();
        vset(visited, n, 0);

        rep(i, k) {
                ll a; cin >> a;
                a--;
                isGov[a] = 1;
                govList.push_back(a);
        }


        rep(i, m) {
                ll u, v; cin >> u >> v;
                u--; v--;
                edges[u].push_back(v);
                edges[v].push_back(u);
        }

        ll maxi = 0;
        ll nodesLeft = n;
        vll sizes;
        trav(elem, govList) {
                ll sz = dfs(elem);
                sizes.push_back(sz);
                nodesLeft -= sz;
                maxi = max(sz, maxi);
        }
        bool flag = 0;
        ll ans = 0;
        rep(i, sizes.size()) {
                if (sizes[i] == maxi && flag == 0) {
                        flag = 1;
                        continue;
                }

                ans += (sizes[i] * (sizes[i] - 1)) / 2;
        }

        nodesLeft += maxi;
        ans += ((nodesLeft) * (nodesLeft - 1)) / 2;
        cout << ans - m << '\n';
        return;
}

int main(int argc , char ** argv) {
        ios_base::sync_with_stdio(false) ;
        cin.tie(NULL) ;

        ll t = 1;
        while (t--) {
                solve();
        }

        return 0 ;
}