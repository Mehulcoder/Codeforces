/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
*	For each index just calculate how many times
*	we have to add it. Once done so, just place the
*	largest element in the position with max frequency
* 	and so on
*/

void solve() {
	ll n, q, ans = 0ll; cin >> n >> q;
	vll v(n, 0), freq(n + 1, 0);

	rep(i, n) cin >> v[i];
	sort(all(v), greater<ll>());

	rep(i, q) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		freq[a]++, freq[b + 1]--;
	}

	rep(i, n)(freq[i] += (i > 0) ? freq[i - 1] : 0ll);
	sort(all(freq), greater<ll>());

	rep(i, n) ans += freq[i] * v[i];

	cout << ans << '\n';
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