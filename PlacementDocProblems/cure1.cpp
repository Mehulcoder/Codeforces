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

vll rankk;
string s;
ll n;
void solve() {
	vset(rankk, 26, 0);
	rep(i, 26) cin >> rankk[i];

	cin >> s;
	n = s.size();

	vll arr(n, 0);
	vll pre(n, 0);
	map<pll, ll> m;
	ll ans = 0ll;
	rep(i, n) {
		arr[i] = rankk[s[i] - 'a'];
		pre[i] = arr[i];
		if (i != 0) pre[i] += pre[i - 1];
		if (i != 0) {
			pll temp = {pre[i - 1], s[i] - 'a'};
			ans += m[temp];
		}
		m[ {pre[i], s[i] - 'a'}]++;
	}

	cout << ans << '\n';
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