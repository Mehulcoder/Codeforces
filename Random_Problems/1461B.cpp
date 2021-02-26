
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
			ll b; cin >> b;
			a[i][j] = (b == '*');
		}
	}

	vvll dp(n, vll(m, 0));
	vvll left, right;
	left = dp;
	right = dp;
	rep(i, n) {
		rep(j, m) {
			if (a[i][j] == 1 && j - 1 >= 0) {
				left[i][j] = left[i][j - 1] + 1;
			}
		}
	}

	rep(i, n) {
		repr(j, m - 1) {
			if (a[i][j] == 1 && j + 1 <= m - 1) {
				right[i][j] = right[i][j + 1] + 1;
			}
		}
	}

	rep(i, n) {
		rep(j, m) {
			if (a[i][j] == 0) continue;

		}
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