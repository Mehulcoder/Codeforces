/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
const ll MOD = 998244353;

ll power(ll a, ll b, ll mod = MOD) {	//a is base, b is exponent
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 1) return (power(a, b - 1) * a) % mod;
	ll q = power(a, b / 2);
	return (q * q) % mod;
}
/*
* For each length of block, from 1-n calculate that how many
* times it can occur. There are 4 ways of composition:
* Has a left and right, has only left, has only right
* has no left and no right. Add the values. Take care of corner
* cases
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	fr(i, 1, n) {
		ll ans = 0;
		if (i != n - 1) ans += (810 * (n - i - 1) * power(10, n - i - 2) + MOD) % MOD;
		ans += (180 * power(10, n - i - 1) + MOD) % MOD;
		if (i != n) cout << ans % MOD << ' ';
		else cout << 10 << '\n';
	}

	return 0 ;
}