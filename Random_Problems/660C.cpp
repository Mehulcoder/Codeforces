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

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, k; cin >> n >> k;

	vll v(n, 0), z(n, 0);
	rep(i, n) cin >> v[i];

	z[0] = (v[0] == 0);
	fr(i, 1, n - 1) {
		z[i] = z[i - 1];
		z[i] += (v[i] == 0);
	}

	ll lo = 0, hi = n, ans = 0, left = -1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		bool flag = 0;

		fr(r, mid - 1, n - 1) {
			ll l = r - mid + 1;
			ll count = z[r];
			if (l - 1 >= 0) {
				count -= z[l - 1];
			}
			if (count <= k) {
				flag = 1;
				left = l;
				break;
			}
		}

		if (flag) {
			ans = max(ans, mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}


	cout << ans << '\n';
	fr(i, left, left + ans - 1) v[i] = 1;

	rep(i, n) cout << v[i] << ' ';
	cout << '\n';

	return 0 ;
}