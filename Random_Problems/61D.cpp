/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

vector<vector<pll>> edges;
vector<bool> visited;
ll rootLeafSum = 0;

/*
* Every edge will be taken twice, except the ones
* in the final path from root to final leaf.
* Choose that path greedily to be the one with max sum
*/

void dfs(ll root, ll sum) {
	visited[root] = 1;
	trav(child, edges[root]) {
		if (!visited[child.f]) {
			dfs(child.f, sum + child.s);
		} else if (edges[root].size() == 1)
			rootLeafSum = max(rootLeafSum, sum);
	}

	return;
}

void solve() {
	ll n, ans = 0; cin >> n;
	edges.resize(n);
	vset(visited, n, 0);
	rep(i, n - 1) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		edges[a].push_back({b, w});
		edges[b].push_back({a, w});
		ans += 2 * w;
	}

	dfs(0, 0);
	ans -= rootLeafSum;
	cout << ans << '\n';
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