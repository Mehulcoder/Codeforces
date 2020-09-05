/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
const ll MOD = 1e18 + 1;

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

void solve() {
	string k; cin >> k;
	ll s; cin >> s;
	vll v;
	ll sum = 0;
	rep(i, k.size()) {
		v.push_back(k[i] - '0');
		sum += v[i];
	}

	if (sum <= s) {
		cout << 0  << '\n';
		return;
	}

	ll diff = sum - s;
	ll n = v.size();
	ll start = n - 1, ans = 0;
	while (diff > 0 && start >= 0) {
		if (start == n - 1) {
			ans += 10 - v[n - 1];
			diff -= v[n - 1] - 1;
		} else {
			ans += (9 - v[start]) * power(10, n - 1 - start);
			diff -= v[start];
		}
		start--;
		while (start >= 0 && v[start] == 9) {
			diff -= 9;
			start--;
		}
	}

	cout << ans << '\n';
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