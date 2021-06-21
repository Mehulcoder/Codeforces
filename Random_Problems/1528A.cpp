
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


/**
 * You just need to choose the boundries of the ranges for each of the vertices
 * the answer will lie on those boundries only, so just see what is the best answer
 * that you can get if you choose l and what is the best you can get if you choose r
 * for the root, choose the one which gives the maximum contribution. Use dp to store the
 * results for each state this way you will visit each vertex twice at maximum, making
 * the time complexity as O(V)
 */

ll n;
vvll edges;
vvll ranges;
vll vis;
vvll dp;
ll dfs(ll ind, ll node, ll par = -1) {
	ll &anss = dp[ind][node];

	if (anss != -1) {
		return anss;
	}

	ll ans = 0;
	trav(child, edges[node]) {
		if (child == par) continue;
		ll a = dfs(0, child, node);
		ll b = dfs(1, child, node);
		ans += max(a + abs(ranges[0][child] - ranges[ind][node]), b + abs(ranges[1][child] - ranges[ind][node]));
	}

	return anss = ans;
}
void solve() {
	edges.clear();
	ranges.clear();
	vis.clear();
	dp.clear();
	cin >> n;
	ranges.resize(2, vll(n, 0));
	edges.resize(n);
	vis.resize(n, 0);
	dp.resize(2, vll(n, -1));

	rep(i, n) {
		cin >> ranges[0][i] >> ranges[1][i];
	}

	rep(i, n - 1) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}


	cout << max(dfs(0, 0), dfs(1, 0)) << endl;
	return;

}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}