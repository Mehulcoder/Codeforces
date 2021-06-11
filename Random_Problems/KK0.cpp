
/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

void solve() {
	ll n, q; cin >> n >> q;

	vll x(n, 0);
	rep(i, n) cin >> x[i];

	map<ll, ll> mp;
	rep(i, n) {
		mp[x[i]]++;
	}

	rep(i, q) {
		ll j; cin >> j;
		if (mp[j] != 0) {
			cout << mp[j] << endl;
		} else {
			cout << max(mp[j - 1], mp[j + 1]) << endl;
		}
	}

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