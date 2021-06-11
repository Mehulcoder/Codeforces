
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

	ll maxi = *max_element(all(a));

	vll b = a;
	sort(a.begin(), a.begin() + maxi);
	sort(a.begin() + maxi, a.end());

	sort(b.begin() + n - maxi, b.end());
	sort(b.begin(), b.begin() + n - maxi);


	bool ok1 = 1;
	bool ok2 = 1;
	rep(i, maxi) {
		if (a[i] != i + 1) {
			ok1 = 0;
			break;
		}
	}

	fr(i, maxi, n - 1) {
		if (a[i] != i - maxi + 1) {
			ok1 = 0;
			break;
		}
	}

	rep(i, n - maxi) {
		if (b[i] != i + 1) {
			ok2 = 0;
			break;
		}
	}


	fr(i, n - maxi, n - 1) {
		if (b[i] != i - n + maxi + 1) {
			ok2 = 0;
			break;
		}
	}

	if (ok1 && ok2 && 2 * maxi != n) {
		cout << 2 << endl;
	} else if (ok1 || ok2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	if (ok1)
		cout << maxi << " " << n - maxi << endl;
	if (ok2 && (2 * maxi != n))
		cout << n - maxi << " " << maxi << endl;
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