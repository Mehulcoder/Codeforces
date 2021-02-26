
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

	ll s = 0;
	rep(i, n) {
		cin >> a[i];
		s += a[i];
	}

	rep(k, n) {
		if (s % (n - k) != 0) continue;
		ll sum = s / (n - k);

		ll groups = 0;
		ll i = 0;
		ll ss = 0;
		bool ok = 1;
		while (i < n) {
			ss += a[i];
			if (ss == sum) {
				groups++, ss = 0;
			} else if (ss > sum) {
				ok = 0;
				break;
			}
			i++;
		}

		if (ok) {
			cout << n - groups << endl;
			return;
		}
		// cout << -1 << endl;
	}

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