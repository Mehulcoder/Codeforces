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


/*
*	dp[i][j] ----> The minimum I can get if a use j for i
*	The greedy here is: If smaller values are not useful for smaller a[i]s
*	They obviously won't be useful for larger a[i]s
*/



ll n;
vector<ll> a;
ll dp[205][405];
ll calc(ll p, ll t) {
	if (p == n) return 0;
	if (t == 2 * n + 1) return INF;
	if (dp[p][t] != -1) return dp[p][t];
	return dp[p][t] = min(calc(p, t + 1), calc(p + 1, t + 1) + abs(a[p] - t));
}

void solve() {
	cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	sort(all(a));

	fil(dp, -1);
	cout << calc(0, 1) << "\n";

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