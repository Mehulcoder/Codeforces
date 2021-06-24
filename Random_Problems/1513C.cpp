
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

/**
 * The main logic behind this problem is that
 * each digit has its own contribution to the
 * number of digits after the m operations on
 * the number.
 * So, here our state, dp[i][j] -> Number of
 * digits the digit i expands into after j
 * operations are done on it.
 */


const ll m = 2e5 + 30;
string s;
ll dp[m + 1][10];
void pre() {
	fil(dp, 0);
	rep(j, 10) {
		dp[0][j] = 1;
	}
	fr(i, 1, m) {
		fr(j, 0, 9) {
			if (j != 9)
				dp[i][j] = dp[i - 1][j + 1];
			else
				dp[i][j] = dp[i - 1][0] + dp[i - 1][1];

			dp[i][j] %= MOD;
		}
	}
}

void solve() {
	ll M;
	cin >> s >> M;

	ll ans = 0;
	trav(elem, s) {
		ans += dp[M][elem - '0'];
		ans %= MOD;
	}

	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	pre();
	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}