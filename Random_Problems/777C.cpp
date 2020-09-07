/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, m, k; cin >> n >> m;
	vvll a(n, vll(m, 0));

	vvll dp(n, vll(m, 1));
	vll dpp(n, 1);
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
			if (i == 0) continue;
			ll temp = (a[i - 1][j] <= a[i][j]) ? (dp[i - 1][j] + 1) : (1);
			dp[i][j] = max(dp[i][j], temp);
			dpp[i] = max(dpp[i], dp[i][j]);
		}
	}

	cin >> k;
	rep(i, k) {
		ll l, r; cin >> l >> r;
		l--; r--;
		ll currUp = r - dpp[r] + 1;
		if (l >= currUp) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0 ;
}