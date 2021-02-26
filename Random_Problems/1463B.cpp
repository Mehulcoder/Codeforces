
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
	ll n; cin >> n;

	vll a(n, 0);
	rep(i, n) cin >> a[i];

	ll s = 0, odd = 0, even = 0;
	rep(i, n) {
		s += a[i];
		if (i % 2 == 0) even += a[i];
		if (i % 2 != 0) odd += a[i];
	}

	if (2 * (odd - n / 2) <= s) {
		rep(i, n) {
			if (i % 2 == 0) cout << a[i] << " ";
			else cout << 1 << " ";
		}
	} else {
		rep(i, n) {
			if (i % 2 != 0) cout << a[i] << " ";
			else cout << 1 << " ";
		}
	}
	cout << endl;
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