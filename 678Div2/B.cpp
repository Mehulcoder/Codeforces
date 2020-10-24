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
const ll MOD = 1e9 + 7;

void solve() {
	ll n;
	cin >> n;


	vector<vector<ll>> ans(n, vector<ll> (n, 0));
	for (ll i = 0; i < n; i++)
		ans[i][i] = 4, ans[n - i - 1][i] = 1;

	if (n & 1) {
		ans[0][n / 2] = 8;
		ans[n - 1][n / 2] = 8;
		ans[n / 2][0] = 8;
		ans[n / 2][n - 1] = 8;
	}

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
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