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


const ll N = 3005;

ll n;
ld p[N];
ld dp[N][N];
ld get(ll pos, ll headCount) {
	if (pos == n) return headCount == 0;
	if (headCount < 0) return 0;

	ld &anss = dp[pos][headCount];
	if (anss != -1.0) return anss;

	return anss = (p[pos] * get(pos + 1, headCount - 1) + (1 - p[pos]) * (get(pos + 1, headCount)));
}

void solve() {
	cin >> n;
	rep(i, n) cin >> p[i];

	ld ans = 0;
	rep(i, N) {
		rep(j, N) {
			dp[i][j] = -1;
		}
	}

	fr(j, (n + 1) / 2, n) {
		ans += get(0, j);
	}

	cout << fixed << setprecision(12) << ans << '\n';
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