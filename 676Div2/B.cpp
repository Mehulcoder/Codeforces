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
	ll m = n;
	vector<string> v(n);
	rep(i, n) cin >> v[i];

	vll temp1;
	temp1.push_back(v[0][1] - '0');
	temp1.push_back(v[1][0] - '0');

	sort(all(temp1));

	vll temp2;
	temp2.push_back(v[n - 1][m - 2] - '0');
	temp2.push_back(v[m - 1][n - 2] - '0');

	sort(all(temp2));

	auto p = v[n - 1][m - 2] - '0';
	auto q = v[m - 2][n - 1] - '0';

	vector<pll> ans;
	if (temp1[0] == 1 && temp1[1] == 1) {
		if (p != 0) {
			ans.push_back({n, m - 1});
		}
		if (q != 0) {
			ans.push_back({m - 1, n});
		}
	} else if (temp1[0] == 0 && temp1[1] == 0) {
		if (p != 1) {
			ans.push_back({n, m - 1});
		}
		if (q != 1) {
			ans.push_back({m - 1, n});
		}
	} else if (p == 1 && q == 1) {
		if (v[0][1] != '0') {
			ans.push_back({1, 2});
		}
		if (v[1][0] != '0') {
			ans.push_back({2, 1});
		}
	} else if (p == 0 && q == 0) {
		if (v[0][1] != '1') {
			ans.push_back({1, 2});
		}
		if (v[1][0] != '1') {
			ans.push_back({2, 1});
		}
	} else {
		if (v[0][1] != '0') {
			ans.push_back({1, 2});
		}
		if (v[1][0] != '0') {
			ans.push_back({2, 1});
		}
		if (p != 1) {
			ans.push_back({n, m - 1});
		}
		if (q != 1) {
			ans.push_back({m - 1, n});
		}
	}


	cout << ans.size() << '\n';
	rep(i, ans.size()) {
		cout << ans[i].f << " " << ans[i].s << '\n';
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