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

/*

* Think of it like dijsktra. What would be the answer for the place
* with minimum cost? Itself. Right? Why would we want to go to some other
* place.

* Now this place has some neighbours, so this place "might" be a nice option
* for them. Think similary for others

* Push all the {cost, node} pairs to the set. So that the min is always on the top
* Now choose the min and try to update neighbours, mark top as visited, pop the top.
* Do till the set has > 0 elements

*/

vector<vector<pll>> edges;
void solve() {
	ll n, m; cin >> n >> m;
	edges.resize(n);

	rep(i, m) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}


	vll a(n);
	rep(i, n) cin >> a[i];

	set<pll> s;
	rep(i, n) {
		s.insert({a[i], i});
	}

	vector<bool> vis(n, 0);
	while (!s.empty()) {
		auto root = *(s.begin());
		s.erase(s.begin());

		trav(child, edges[root.s]) {
			if (vis[child.f]) continue;

			ll to = child.f;
			ll wt = child.s;

			if (2 * wt + root.f < a[to]) {
				s.erase({a[to], to});
				a[to] = 2 * wt + root.f;
				s.insert({a[to], to});
			}
		}

		vis[root.s] = 1;
	}

	trav(elem, a) {
		cout << elem << ' ';
	}

	cout << '\n';
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