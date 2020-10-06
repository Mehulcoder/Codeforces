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
const ll mod = 1e9 + 7;



int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	string s;
	cin >> s;
	ll ans = 0ll;
	ll n = s.size();
	string ss = s;
	rep(i, n) s[i] = ss[n - i - 1];
	ll c = 1, now = 0;

	rep(i, n) {
		ll num = (ll)(s[i] - '0');

		//num%=mod;
		ll cur = (ll)(n - i) * (n - i - 1) / 2;
		ans += num * (c * (cur % mod) + now) % mod;

		ans %= mod;
		now += (((i + 1) * c) % mod);
		now %= mod;
		c *= 10;
		c %= mod;
	}
	cout << ans % mod << endl;
	return 0;
}