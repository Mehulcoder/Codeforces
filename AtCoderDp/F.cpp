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

const ll N = 3e3 + 10;

string s, t;
ll n, m;
ll dp[N][N];
ll get(ll i, ll j) {
	if (i >= n || j >= m) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == t[j]) return dp[i][j] = 1 + get(i + 1, j + 1);
	return dp[i][j] = max(get(i + 1, j), get(i, j + 1));
}

string get2(ll i, ll j) {
	if (i >= n || j >= m) return "";

	if (s[i] == t[j]) return s[i] + get2(i + 1, j + 1);

	if (get(i + 1, j) >= get(i, j + 1)) return get2(i + 1, j);
	return get2(i, j + 1);
}

void solve() {
	cin >> s >> t;
	n = s.size();
	m = t.size();

	fil(dp, -1);
	get(0, 0);

	cout << get2(0, 0) << '\n';

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