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

const ll N = 1e5 + 5;

ll n, m;
vll edges[N];
ll dp[N];
ll get(ll root) {
	ll ans = 0;

	if (dp[root] != -1) return dp[root];

	trav(child, edges[root]) {
		ans = max(ans, 1 + get(child));
	}

	return dp[root] = ans;
}

void solve() {
	cin >> n >> m;

	fil(dp, -1);
	rep(i, m) {
		ll x, y; cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
	}

	ll ans = 0ll;
	rep(i, n) {
		ans = max(ans, get(i));
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