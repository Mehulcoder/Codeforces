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
ll a[N], dp[N][N];
ll get(ll i, ll j) {
	if (i > j) return 0;

	ll &ans = dp[i][j];
	if (ans != -1) return ans;

	return ans = max(a[j] + min(get(i, j - 2), get(i + 1, j - 1)), a[i] + min(get(i + 2, j), get(i + 1, j - 1)));
}

void solve() {
	cin >> n;
	ll sum = 0;
	rep(i, n) cin >> a[i];
	rep(i, n) sum += a[i];

	fil(dp, -1);

	ll x = get(0, n - 1);
	ll y = sum - x;
	cout << x - y << '\n';

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