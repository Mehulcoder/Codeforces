/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


void solve() {
	ll n, m; cin >> n >> m;

	set<vll> s;
	bool ok1 = 0;
	bool ok2 = 0;
	ok1 = !(m % 2);
	rep(i, n) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b == c) ok2 = 1;
		s.insert({a, b, c, d});
	}


	cout << ((ok2 && ok1) ? ("YES") : ("NO")) << '\n';
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