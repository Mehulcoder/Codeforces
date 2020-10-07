/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

// Find closest group of k+1 zeroes ---> Ones in our new array

void solve() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;

	vector<ll> v(n);
	rep(i, n) v[i] = !(s[i] - '0');

	vll pre(n, 0);
	rep(i, n) {
		pre[i] = v[i];
		if (i != 0) pre[i] += pre[i - 1];
	}

	map<ll, ll> m;
	ll best = INF;
	rep(i, n) {
		if (v[i] == 1) {
			m[pre[i]] = i;
			if (m.find(pre[i] - k) != m.end()) {
				best = min(best, i - m[pre[i] - k] + 1);
			}
		}
	}

	cout << best - 2 << '\n';
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