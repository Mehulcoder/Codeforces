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
	ll ans, x, y, c1, c2, c3, c4, c5, c6;
	cin >> x >> y;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	c2 = min(c2, c1 + c3);
	c3 = min(c3, c2 + c4);
	c4 = min(c4, c3 + c5);
	c5 = min(c5, c4 + c6);
	c6 = min(c6, c5 + c1);
	c1 = min(c1, c6 + c2);
	if (x <= 0 && y >= 0) ans = y * c2 - x * c3;
	else if (x >= 0 && y <= 0) ans = x * c6 - y * c5;
	else if (x <= 0 && y <= 0) {
		if (x > y) ans = (x - y) * c5 - x * c4;
		else ans = (y - x) * c3 - y * c4;
	} else {
		if (x < y) ans = (y - x) * c2 + x * c1;
		else ans = (x - y) * c6 + y * c1;
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