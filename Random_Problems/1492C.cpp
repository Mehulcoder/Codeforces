
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
	ll m, n; cin >> m >> n;

	string s, t; cin >> s >> t;
	vvll pos(26);

	rep(i, m) {
		pos[s[i] - 'a'].push_back(i);
	}

	vll low(n, -1);
	vll high(n, -1);
	ll ans = 0;
	low[0] = (pos[t[0] - 'a'][0]);
	high[n - 1] = (pos[t.back() - 'a'].back());

	fr(i, 1, n - 1) {
		low[i] = *upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), low[i - 1]);
	}
	frr(i, n - 2, 0) {
		high[i] = pos[t[i] - 'a'][lower_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), high[i + 1]) - pos[t[i] - 'a'].begin() - 1];
	}
	// trace(low, high);
	fr(i, 1, n - 1) {
		ans = max(ans, high[i] - low[i - 1]);
	}

	cout << ans << endl;

	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;

	while (t--) {
		solve();
	}

	return 0 ;
}