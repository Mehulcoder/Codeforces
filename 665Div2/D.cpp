/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;

vvll edges;
vll multi;
ll dfs(ll root, ll parent = -1) {
	ll count = 0;
	trav(child, edges[root]) {
		if (child == parent) continue;
		ll temp = dfs(child, root);
		count += temp;
		multi.push_back(temp);
	}

	return count + 1;
}

void solve() {
	ll n; cin >> n;
	vset(edges, n, vll(0));
	multi.clear();
	rep(i, n - 1) {
		ll u, v; cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(0);
	rep(i, multi.size()) {
		multi[i] *= (n - multi[i]);
	}

	sort(all(multi), greater<ll>());
	multi.pop_back();
	rep(i, n - 1) multi[i] %= MOD;
	ll m; cin >> m;
	vll factors(m);
	rep(i, m) cin >> factors[i];

	sort(all(factors), greater<ll>());

	ll ans = 0;
	if (factors.size() <= n - 1) {
		rep(i, factors.size()) {
			ans = (ans % MOD) + (factors[i] * multi[i]) % MOD;
			ans %= MOD;
		}
		fr(i, factors.size(), n - 2) {
			ans += (multi[i]) % MOD;
			ans %= MOD;
		}
	} else {
		ll extra = factors.size() - n + 1;
		ll first = 1;
		rep(i, extra) {
			first *= factors[i];
			first %= MOD;
		}
		factors[extra] *= first;
		factors[extra] %= MOD;
		rep(i, n - 1) {
			ans = (ans % MOD + (multi[i] * factors[extra + i]) % MOD) % MOD;
			ans %= MOD;
		}
	}

	cout << (ans + MOD) % MOD << '\n';
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