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

const ll N = 1e5 + 10;
vll edges[N];
ll dp[N][2];
ll n;
ll dfs(ll root, bool col, ll par) {
	if (dp[root][col] != -1) return dp[root][col];

	ll ans = 1;
	trav(child, edges[root]) {
		if (child != par) {
			ll temp = 0;
			if (!col) {
				temp += dfs(child, col, root);
				temp %= MOD;
				temp += dfs(child, !col, root);
				temp %= MOD;
			} else {
				temp += dfs(child, !col, root);
				temp %= MOD;
			}
			temp = (temp % MOD + MOD) % MOD;
			ans *= temp;
			ans = (ans % MOD + MOD) % MOD;
		}
	}

	return dp[root][col] = ans;
}

void solve() {
	cin >> n;

	fil(dp, -1);
	rep(i, N)edges[i].clear();

	rep(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}


	ll ans = 0ll;
	ans += dfs(0, 0, -1);
	ans += dfs(0, 1, -1);

	cout << (ans % MOD + MOD) % MOD << '\n';
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