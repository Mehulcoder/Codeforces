/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

ll n, m;
vll a, b, c(1), d(1);
vvll dp;

/*
* dp[i][j]: Best cost for index ending at i, j dough left
* For each type we can take at max floor(ai/bi) of its quantinty
* also j-(quant)*ci>=0
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	cin >> n >> m;
	vset(dp, m + 1, vll(n + 1, -1));

	a.push_back(0);
	b.push_back(0);
	cin >> c[0]; cin >> d[0];

	rep(i, m) {
		ll ai, bi, ci, di;
		cin >> ai >> bi >> ci >> di;
		a.push_back(ai);
		b.push_back(bi);
		c.push_back(ci);
		d.push_back(di);
	}

	rep(j, n + 1) dp[0][j] = (j / c[0]) * (d[0]);

	ll ans = -1;
	fr(i, 1, m) fr(j, 0, n) {
		rep(lambda, a[i] / b[i] + 1) {
			if (j - lambda * c[i] >= 0) {
				dp[i][j] = max(dp[i][j], lambda * d[i] + dp[i - 1][j - lambda * c[i]]);
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << '\n';
	return 0 ;
}