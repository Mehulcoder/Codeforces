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

const ll N = 105;

ll n, k;
ll a[N];
ll dp[N][100005];
ll preDp[N][100005];

void solve() {
	cin >> n >> k;
	rep(i, n) cin >> a[i];

	fil(dp, 0);
	fil(preDp, 0);

	rep(j, a[0] + 1) {
		dp[0][j] = 1;
	}

	rep(j, k + 1) {
		preDp[0][j] = dp[0][j];
		if (j > 0) preDp[0][j] += preDp[0][j - 1];
	}


	fr(i, 1, n - 1) {
		rep(j, k + 1) {
			dp[i][j] = preDp[i - 1][j];
			if (j > a[i]) dp[i][j] -= preDp[i - 1][j - a[i] - 1];
			preDp[i][j] = dp[i][j];
			if (j > 0) preDp[i][j] += preDp[i][j - 1];

			dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
			preDp[i][j] = (preDp[i][j] % MOD + MOD) % MOD;
		}
	}


	cout << (dp[n - 1][k] % MOD + MOD) % MOD << '\n';
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