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

string k;
ll d;
ll n;
ll dp[101][10004][2];

ll get(ll rem, ll pos, bool isEqualYet) {
	if (pos == n) return (!((rem % d + d) % d));
	ll ans = 0ll;

	ll &anss = dp[rem][pos][isEqualYet];
	if (anss != -1) return anss;

	/**
	 * It means till now the prefix is less
	 * so we can take any number
	*/
	if (!isEqualYet) {
		rep(i, 10) {
			ll remm = (rem + i) % d;
			ans += get(remm, pos + 1, 0);
			ans %= MOD;
		}
	} else {
		/**
		 * This means that the digits till now
		 * are equal and now we will have two cases
		 * to handle
		 */
		fr(i, 0, k[pos] - '0' - 1) {
			ll remm = (rem + i) % d;
			ans += get(remm, pos + 1, 0);
			ans %= MOD;
		}

		ll remm = (rem + k[pos] - '0') % d;
		ans += get(remm, pos + 1, 1);
		ans %= MOD;
	}



	return anss = (ans % MOD + MOD) % MOD;;
}

void solve() {
	cin >> k >> d;
	n = k.size();
	fil(dp, -1);

	ll ans = get(0, 0, 1) - 1;
	if (ans == -1) ans = MOD - 1;

	cout << ans << '\n';
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