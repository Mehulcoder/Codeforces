/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)

/*
* Before we added any new edge, there's always only one path
* b/w a-b, we can increase steps in ab by walking any edge back and
* forth. We can make the new distance: ab+2*Z. Means: we can increase
* the number of steps but we cannot change the parity of them.

* What if we add an edge in the tree now, say b/w x and y.
* Now we can travel from a-b by three ways rather than 1 previously
* 1) a-b directly
* 2) a-x + x-y + y-b which is same as a-x+y-b+1
* 2) a-y + 1 + x-b
* Can we guarantee that the parity of any of the last two is different from 1)?
* Yes if we take x-y one/odd times and direct path x-y is even.
*/

/*
* LCA explained nicely on: https://cp-algorithms.com/graph/lca_binary_lifting.html
* as usual.
*/

ll n;
vvll edges, up;
vll tin, tout, level;
ll timer, l;

void dfs(ll root, ll parent, ll lev = 0) {
	tin[root] = ++timer;
	level[root] = lev;

	//2**jth parent of root
	up[root][0] = parent;
	fr(j, 1, l) {
		up[root][j] = up[up[root][j - 1]][j - 1];
	}

	trav(child, edges[root]) {
		if (child == parent) continue;
		dfs(child, root, lev + 1);
	}

	tout[root] = ++timer;
	return;
}

bool isAncestor(ll u, ll v) {
	//Visit parent first, explore child, leave child, leave parent
	return (tin[u] <= tout[v] && tout[u] >= tout[v]);
}

ll lca(ll u, ll v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;


	// If you've thrown rope upper than or at the ancestor
	// SIDENOTE: Think! any parent of lca is your ancestor too.
	// Calm down throw it a little 'bit' down. Else just jump
	// up that rope. Nice and easy. At end nmw you'll end up
	// at the child of the lca
	//
	frr(j, l, 0) {
		if (!isAncestor(up[u][j], v)) {
			//You jump up
			u = up[u][j];
		}

	}
	return up[u][0];
}

ll distance(ll u, ll v) {
	ll d1 = level[u], d2 = level[v];
	ll d3 = level[lca(u, v)];

	return (d1 + d2 - 2 * d3);
}

void solve() {
	cin >> n;
	vset(edges, n, vll(0));
	tin.resize(n, 0);
	tout.resize(n, 0);
	level.resize(n, 0);
	timer = 0;
	l = ceil(log2(n));
	vset(up, n, vll(l + 1));

	rep(i, n - 1) {
		ll u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(0, 0);
	ll q; cin >> q;
	rep(i, q) {
		ll x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		x--; y--; a--; b--;
		ll ab = distance(a, b);
		ll ax = distance(a, x);
		ll bx = distance(b, x);
		ll ay = distance(a, y);
		ll by = distance(b, y);

		ll withoutXy = ab;
		ll withXy = min(bx + ay, ax + by) + 1;

		ll ans = INF;
		if (withoutXy % 2 == k % 2) {
			ans = withoutXy;
		}

		if (withXy % 2 == k % 2) {
			ans = min(ans, withXy);
		}

		cout << ((ans <= k) ? "YES" : "NO") << '\n';
	}

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