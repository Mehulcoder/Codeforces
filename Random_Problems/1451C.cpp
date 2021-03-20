
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
	ll n, k; cin >> n >> k;

	string a, b; cin >> a >> b;

	vll c1(26, 0), c2(26, 0);
	rep(i, n) {
		c1[a[i] - 'a']++;
		c2[b[i] - 'a']++;
	}

	rep(i, 26) {
		if (c1[i] >= c2[i]) {
			c1[i] -= c2[i];
			if (c1[i] % k) {
				cout << "No" << endl;
				return;
			}
			continue;
		}

		ll needed = c2[i] - c1[i];
		if (needed % k) {
			cout << "No" << endl;
			return;
		}

		rep(j, i) {
			c1[i] += c1[j];
			c1[j] = 0;
			if (c1[i] >= c2[i]) {
				c1[i] -= c2[i];

				needed = 0;
				break;
			} else {
				needed = c2[i] - c1[i];
			}
		}

		if (needed != 0) {
			cout << "No" << endl;
			return;
		}

	}

	cout << "Yes" << endl;
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