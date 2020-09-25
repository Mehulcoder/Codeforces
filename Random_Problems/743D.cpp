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


ll n; vll a;
vvll edges;
vll sums;
vll dp;
bool hasTwoChild = 0;

ll makeSum(ll root, ll par = -1) {
	sums[root] = a[root];
	trav(child, edges[root]) {
		if (child == par) continue;
		sums[root] += makeSum(child, root);
	}

	return sums[root];
}

void preCalcMaxi(ll root, ll par = -1) {
	dp[root] = sums[root];

	trav(child, edges[root]) {
		if (child == par) continue;
		preCalcMaxi(child, root);
		dp[root] = max(dp[root], dp[child]);
	}

	return;
}

ll dfs(ll root, ll par = -1) {
	ll ans = -INF;
	vll temp;

	if (edges[root].size() > 2) hasTwoChild = 1;

	ll maxi = -INF;
	ll sMaxi = -INF;
	trav(child, edges[root]) {
		if (child == par) continue;
		if (dp[child] >= maxi) {
			sMaxi = maxi;
			maxi = dp[child];
		} else {
			sMaxi = max(dp[child], sMaxi);
		}
	}

	if (sMaxi != -INF) {
		ans = maxi + sMaxi;
	}

	trav(child, edges[root]) {
		if (child == par) continue;
		ans = max(ans, dfs(child, root));
	}

	return ans;
}

void solve() {
	cin >> n;
	a.resize(n, 0);
	rep(i, n) cin >> a[i];
	dp.resize(n + 1, -INF);
	sums.resize(n + 1, 0);

	edges.resize(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	makeSum(0);
	preCalcMaxi(0);

	hasTwoChild = hasTwoChild || (edges[0].size() > 1);
	ll ans = -INF;
	ans = dfs(0);
	if (!hasTwoChild) cout << "Impossible" << '\n';
	else cout << ans << '\n';
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