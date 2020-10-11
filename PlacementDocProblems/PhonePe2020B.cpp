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

ll n;
vvll edges;

map<pll, ll> levelDp;
map<pll, ll> pathDp;

ll getLevel(ll root, ll par = -1) {
	ll ans = 0;

	if (levelDp.find({root, par}) != levelDp.end()) {
		return levelDp[ {root, par}];
	}

	trav(child, edges[root]) {
		if (child == par) continue;
		ans = max(ans, getLevel(child, root) + 1);
	}

	return levelDp[ {root, par}] = ans;
}

ll longestPath(ll root, ll par = -1) {
	ll ans = 1;

	if (pathDp.find({root, par}) != pathDp.end()) {
		return pathDp[ {root, par}];
	}

	ll a = 0, b = 0;
	trav(child, edges[root]) {
		if (child == par) continue;
		ll childDepth = 1 + getLevel(child, root);
		if (childDepth > a) {
			b = a;
			a = childDepth;
		} else {
			b = max(b, childDepth);
		}

		//Longest path doesn't include root
		ans = max(ans, longestPath(child, root));
	}
	// The longest path includes root.
	ans = max(ans, a + b + 1);
	return pathDp[ {root, par}] = ans;
}

void solve() {
	cin >> n;
	edges.resize(n);
	rep(i, n - 1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	ll ans = 0;
	rep(root, n) {
		trav(child, edges[root]) {
			ans = max(ans, (longestPath(root, child) - 1) * (longestPath(child, root) - 1));
		}
	}

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