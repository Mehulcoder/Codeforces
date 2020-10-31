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

const ll N = 100;

ll n, W;
ll w[N], v[N];
ll dp[100005][N];

/*
	dp[i][j] ===> Weights required till position j to make the
	sum equal to i.
*/

void solve() {
	cin >> n >> W;
	rep(i, n) cin >> w[i] >> v[i];

	ll sumVal = 0;
	rep(i, n) sumVal += v[i];

	rep(i, sumVal + 1) {
		rep(j, n) {
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	ll ans = 0ll;
	fr(i, 1, sumVal) {
		dp[i][0] = ((v[0] == i) ? w[0] : INF);
		if (dp[i][0] <= W) ans = max(ans, (ll)i);

	}

	rep(j, n) {
		dp[0][j] = 0;
		if (dp[0][j] <= W) ans = max(ans, 0ll);

	}

	fr(i, 1, sumVal) {
		fr(j, 1, n - 1) {
			ll a = ((i - v[j] >= 0) ? (w[j] + dp[i - v[j]][j - 1]) : INF);
			ll b = dp[i][j - 1];
			dp[i][j] = min(a, b);
			if (dp[i][j] <= W) ans = max(ans, (ll)i);
		}
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