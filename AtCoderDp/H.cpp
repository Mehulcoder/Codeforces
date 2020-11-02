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

ll n, m;
char arr[1003][1003];
ll dp[1003][1003];
ll get(ll i, ll j) {
	if (i >= n || j >= m) return 0;
	if (i == n - 1 && j == m - 1) return 1;
	if (arr[i][j] == '#') return 0;

	if (dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = ((get(i + 1, j) + get(i, j + 1)) % MOD + MOD) % MOD;
}

void solve() {
	cin >> n >> m;

	fil(dp, -1);
	rep(i, n) {
		rep(j, m) {
			cin >> arr[i][j];
		}
	}


	cout << get(0, 0) << '\n';
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