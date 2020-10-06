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
	ll n, m; cin >> n >> m;

	vvll a(n, vll(m, 0));

	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
	}

	ll ans = 0ll;
	rep(i, n) {
		rep(j, m) {
			ll v[4];
			v[0] = a[i][j];
			v[1] = a[i][m - 1 - j];
			v[2] = a[n - 1 - i][m - 1 - j];
			v[3] = a[n - 1 - i][j];
			sort(v, v + 4);
			ans += abs(a[i][j] - v[1]);
		}
	}
	cout << ans << "\n";
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