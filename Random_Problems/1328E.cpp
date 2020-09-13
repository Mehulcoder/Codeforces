/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)


ll n, m, timer;
vvll edges;
vll tin, tout, level, parent;

/*
* Make the deepest node as u. Quite easy to understand. Cool? Done!
* How to find the deepest one? Maintain levels using dfs. Done!
* Path from root to deepest should have either all the nodes in v
* or some of the nodes in v can be the direct childs of some nodes
* on the path from root to deepest.
* How to do that fast? Observe: If you change all the nodes in v, except deepest
* to their parent. Then you just need to find if the nodes in v lie on path
* from root to v. Cool? Done!
* How to do that fast? You just need to tell if all the nodes in v are ancestor
* of the deepest. How to do that? Maintain entry and exit times. Intuitive after that.
* Done! Boom! Peace!
*/
void getInOut(ll root, ll parr = -1, ll lev = 0) {
	parent[root] = parr;
	tin[root] = timer++;
	level[root] = lev;

	trav(child, edges[root]) {
		if (parr != child) {
			getInOut(child, root, lev + 1);
		}
	}

	tout[root] = timer++;
	return;
}

bool isAncestor(ll u, ll v) {
	//Visit parent first, explore child, leave child, leave parent
	return (tin[u] <= tout[v] && tout[u] >= tout[v]);
}

void solve() {
	cin >> n >> m;
	vset(tin, n, 0);
	vset(tout, n, 0);
	vset(edges, n, vll(0));
	vset(level, n, 0);
	vset(parent, n, -1);

	timer = 0;

	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	getInOut(0);

	while (m--) {
		ll k; cin >> k;
		vll v(k, 0);
		rep(i, k) {
			cin >> v[i];
			v[i]--;
		}

		int deepest = v[0];
		rep(i, k) {
			if (level[v[i]] > level[deepest]) deepest = v[i];
		}

		//Replace every node except deepest in the v with its parent
		rep(i, k) {
			if (v[i] != deepest && parent[v[i]] != -1) {
				v[i] = parent[v[i]];
			}
		}

		//Find if each of them is an ancestor of the deepest
		bool yes = 1;
		rep(i, k) {
			if (v[i] != deepest) {
				if (!isAncestor(v[i], deepest)) yes = 0;
			}
		}

		cout << ((yes == 1) ? ("YES") : ("NO")) << '\n';
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