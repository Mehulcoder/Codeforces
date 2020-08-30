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
const ll MOD = 1e9 + 7;

/*
* Basically we need to prime factorize x. And iterate on them.
* For each prime pi we need the contribution of pi, pi**2, pi**3...
* to numbers in [1, n] . Number of multiple of pi will give how many times pi has contributed.
* Eg: 1-30 p = 2:
* 2^1 contributes: (2^1)^(30/2)
* 2^2 contributes: (2^2)^(30/2^2): But they are already once counted with 2^1
* So the total contribution of above two is: (2^1)^(30/2)*(2^1)^(30/20^2)
* similary for 3rd power. Therefore, net contri = (2^1)^(30/2)*(2^1)^(30/20^2)*(2^1)^(30/2^3)
* similarly for 4th, therefore net: (2^1)^(30/2)*(2^1)^(30/20^2)*(2^1)^(30/2^3)*(2^1)^(30/2^4)
*/

/*
* Proof: Say contri of p^(i-1) = (n/p^(i-1)) ---->c1
* contri of p^(i) = n/(p^i). But that has contri of
* p^(i-1) too. Net contri of p^(i-1) = (n/p^(i-1))-(n/p^(i))---->c2
* Therefore the result for them both can be written as
* (p^(i-1))^(c1))*(p^i)^c2 == p^((i-1)*(n/p^(i-1)) * p^((i-1)*n/p^(i))
* This is valid for all i
*/

vector<pll> factors;

ll power(ll a, ll b, ll mod = MOD) {	//a is base, b is exponent
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % mod;
	ll q = power(a, b / 2);
	return (q * q) % mod;
}

void primeFactors(ll x) {
	bool flag = 0;
	while (x % 2 == 0) {
		x /= 2;
		if (!flag) {
			factors.push_back({2, 1});
			flag = 1;
		} else {
			factors.back() = {2, (factors.back()).s + 1};
		}
	}

	for (ll i = 3; i <= sqrtl(x); i = i + 2) {
		flag = 0;
		while (x % i == 0) {
			x /= i;
			if (!flag) {
				factors.push_back({i, 1});
				flag = 1;
			} else {
				factors.back() = {i, (factors.back()).s + 1};
			}
		}
	}

	if (x > 2) {
		factors.push_back({x, 1});
	}

	return;

}

ll getExponent(ll n, ll p) {
	ll ans = 0;

	while (n > 0) {
		ans += n / p;
		n /= p;
	}

	return ans;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll x, n; cin >> x >> n;
	primeFactors(x);
	ll ans = 1;

	rep(i, factors.size()) {
		auto temp = factors[i];
		ll exponent = getExponent(n, temp.f);
		ans *= power(temp.f, exponent);
		ans %= MOD;
	}

	cout << ans << '\n';

	return 0 ;
}