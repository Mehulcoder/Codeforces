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

ll n, k;
string s, t;
const ll N = 202;
ll dp[N][N][N];
ll get(ll start, ll aTillNow, ll chancesLeft) {
	if (start == n) return 0;

	ll &anss = dp[start][aTillNow][chancesLeft];
	if (anss != -1) return anss;

	ll ans = get(start + 1, aTillNow, chancesLeft);
	if (s[start] == t[0]) {
		ans = max(ans, get(start + 1, aTillNow + 1, chancesLeft));
	} else if (s[start] == t[1]) {
		ans = max(ans, get(start + 1, aTillNow, chancesLeft) + aTillNow);
	}

	if (chancesLeft > 0) {
		ans = max(ans, get(start + 1, aTillNow + 1, chancesLeft - 1));
		ans = max(ans, get(start + 1, aTillNow, chancesLeft - 1) + aTillNow);
	}

	return anss = ans;
}

void solve() {
	cin >> n >> k;
	cin >> s >> t;

	if (t[0] == t[1]) {
		ll cnt = 0;
		rep(i, n) {
			if (s[i] == t[0]) cnt++;
		}

		cnt = min(n, cnt + k);

		ll res = cnt-- * cnt / 2;
		cout << res << '\n';
		return;
	}

	memset(dp, -1, sizeof(dp));
	cout << get(0, 0, k) << '\n';
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