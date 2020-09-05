/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

vll getFact(ll num) {
	vll ans;
	fr(i, 1, num) {
		if (num % i == 0) ans.push_back(i);
	}

	sort(all(ans));
	reverse(all(ans));
	return ans;
}

void solve() {
	ll n, x, y; cin >> n >> x >> y;

	ll diff = y - x;
	vll fact = getFact(diff);
	ll jmi = 0;
	rep(i, fact.size()) {
		if (fact[i] <= n - 1) {
			jmi = fact[i];
			break;
		}
	}
	ll k = diff / jmi;
	ll i = x / k;
	i = min(i, n - 1 - jmi);
	ll start = x - i * k;
	if (start == 0) start += k;
	ll p = 0;
	rep(i, n) {
		cout << start + p*k << ' ';
		p++;
	}
	cout << '\n';
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