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

const ll N = 22;

ll n;
bool mat[N][N];
ll dp[22][1 << 22];
ll get(ll end, ll mask) {
	if (end == 0) {
		ll ans = 0;
		rep(i, n) {
			if (mat[end][i] && ((mask & (1 << i))) != 0) {
				ans++;
			}
		}

		return ans;
	}

	if (dp[end][mask] != -1)return dp[end][mask];

	ll ans = 0;
	rep(i, n) {
		if (mat[end][i] && ((mask & (1 << i)) != 0)) {
			ans += get(end - 1, mask ^ (1 << i));
			ans %= MOD;
			ans = (ans + MOD) % MOD;
		}
	}

	return dp[end][mask] = ans;

}
void solve() {
	cin >> n;
	fil(dp, -1);
	rep(i, n) {
		rep(j, n) {
			cin >> mat[i][j];
		}
	}

	ll mask = 0;
	rep(i, n) {
		mask |= (1 << i);
	}

	cout << get(n - 1, mask) << endl;;
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