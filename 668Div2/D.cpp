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

/*
* Can alice win in first move? Check for the distance

* Can alice win if no matter where Bob is?
* If da>=(dia)/2. Alice can move to centre of tree and
* catch Bob in the next move.

* Is there some condition, where Bob can always be safe
* Given that above two conditions are not valid?
* Assume that Bob is on the end of the tree, da=4,
* dist b/w a and b is 5. If you analyze, db should be
* greater than 4*2 to be safe in this worst case too.
* => db>2*da for bob to be safe always.

* else alice always catches
*/

ll n, a, b, da, db;
vvll edges;
ll start, depthMax, distAB;
bool done = 0;
void dfs(ll root, ll depth, ll parent = -1) {
	if (depth > depthMax) {
		start = root;
		depthMax = depth;
	}

	if (root == b && done == 0) {
		distAB = depth;
	}

	trav(child, edges[root]) {
		if (child == parent) continue;
		dfs(child, depth + 1, root);
	}

	return;
}

void solve() {
	cin >> n >> a >> b >> da >> db;
	done = 0, distAB = 0, depthMax = 0, start = 0;
	vset(edges, n, vll(0));
	a--; b--;
	rep(i, n - 1) {
		ll aa, bb; cin >> aa >> bb;
		aa--; bb--;
		edges[aa].push_back(bb);
		edges[bb].push_back(aa);
	}

	dfs(a, 0);
	done = 1;
	dfs(start, 0);
	bool alice = 0;
	if (distAB <= da) alice = 1;
	else if (depthMax <= 2 * da) {
		alice = 1;
	} else if (db > 2 * da) {
		alice = 0;
	} else {
		alice = 1;
	}

	string ans = (alice) ? "Alice" : "Bob";
	cout << ans << '\n';
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