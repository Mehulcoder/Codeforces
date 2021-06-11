
/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using ppll = pair<pll, pll>;

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

string s;
void solve() {
	cin >> s;
	ll n = s.size();
	ll ans = 0;
	set <pair<pll, pll>> st;

	ll ii = 0, jj = 0;
	rep(i, n) {
		auto c = s[i];
		if (s[i] == 'N') {
			if (st.find({{ii, jj}, {ii, jj + 1}}) == st.end()) {
				ans += 5;
			} else {
				ans += 1;
			}
			st.insert({{ii, jj}, {ii, jj + 1}});
			st.insert({{ii, jj + 1}, {ii, jj}});
			jj++;
		}
		if (s[i] == 'S') {
			if (st.find({{ii, jj}, {ii, jj - 1}}) == st.end()) {
				ans += 5;
			} else {
				ans += 1;
			}
			st.insert({{ii, jj}, {ii, jj - 1}});
			st.insert({{ii, jj - 1}, {ii, jj}});
			jj--;
		}
		if (s[i] == 'W') {
			if (st.find({{ii, jj}, {ii - 1, jj}}) == st.end()) {
				ans += 5;
			} else {
				ans += 1;
			}
			st.insert({{ii, jj}, {ii - 1, jj}});
			st.insert({{ii - 1, jj}, {ii, jj}});
			ii--;
		}
		if (s[i] == 'E') {
			if (st.find({{ii, jj}, {ii + 1, jj }}) == st.end()) {
				ans += 5;
			} else {
				ans += 1;
			}
			st.insert({{ii, jj}, {ii + 1, jj}});
			st.insert({{ii + 1, jj}, {ii, jj}});
			ii++;
		}
	}

	cout << ans << endl;
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