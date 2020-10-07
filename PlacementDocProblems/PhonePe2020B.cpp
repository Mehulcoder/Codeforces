/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

ll n;
vvll edges;
vll dp;

ll get(ll root, ll parent = -1) {
	ll sz = 1;

	trav(child, edges[root]) {
		if (child != parent) {
			sz += get(child, root);
		}
	}

	return dp[root] = sz;
}

void solve() {
	cin >> n;
	vset(edges, n, vll(0));
	vset(dp, n, 0);

	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	get(0);

	ll ans = 0ll;
	rep(i, n) {
		ans = max(ans, (dp[i] - 1) * (n - dp[i] - 1));
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