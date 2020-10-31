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
ll dp[N][100005];
ll get(ll pos, ll tot) {
	if (tot > W) return -INF;
	if (pos >= n || tot == W) return 0;

	ll &anss = dp[pos][tot];
	if (anss != -1) return anss;

	return anss = max(v[pos] + get(pos + 1, tot + w[pos]), get(pos + 1, tot));
}

void solve() {
	cin >> n >> W;
	rep(i, n) cin >> w[i] >> v[i];

	fil(dp, -1);
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