/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;


void solve() {
	ll x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

	ll ans = 0;
	if (z1 <= y2) {
		ans += 2 * z1;
		y2 -= z1;
		z1 = 0;
		ll temp = min(x1, z2);
		x1 -= temp;
		z2 -= temp;

		ans -= 2 * z2;
	} else {
		ans += 2 * y2;
		z1 -= y2;
		y2 = 0;
		z2 -= min(z2, x1);
		z2 -= min(z2, z1);
		ans -= 2 * z2;
	}

	cout << ans << '\n';
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