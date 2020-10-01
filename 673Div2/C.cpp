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


ll n, k, x, m;
void solve() {
	cin >> n;
	vvll a(n);
	rep(i, n) {
		cin >> x;
		x--;
		a[x].push_back(i);
	}

	vll ans(n + 2, n + n);
	rep(i, n) {
		k = -1;
		m = 0;
		rep(j, a[i].size()) {
			m = max(m, a[i][j] - k);
			k = a[i][j];
		}
		m = max(m, n - k);
		ans[m] = min(ans[m], (ll)i);
	}
	ll mi = n + n;
	fr(i, 1, n) {
		mi = min(mi, ans[i]);
		if (mi > n) {
			cout << "-1" << " ";
		} else
			cout << (mi + 1) << " ";
	}
	cout << "\n";

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