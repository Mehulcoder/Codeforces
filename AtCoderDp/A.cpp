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


ll n;
vll h;

ll dp[100005];
ll get(ll start) {
	if (start == n - 1) return 0;
	if (start >= n) return INF;

	ll &anss = dp[start];
	if (anss != -1) return anss;

	ll ans1 = INF;
	ll ans2 = INF;
	if (start + 1 < n)
		ans1 = get(start + 1) + abs(h[start + 1] - h[start]);
	if (start + 2 < n)
		ans2 = get(start + 2) + abs(h[start + 2] - h[start]);


	return anss = min(ans1, ans2);
}

void solve() {
	cin >> n;
	vset(h, n, 0);
	rep(i, n) cin >> h[i];
	fil(dp, -1);
	cout << get(0) << '\n';
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