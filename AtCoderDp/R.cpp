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


void matMult(vvll &a, vvll &b, ll mod) {
	ll n = a.size();
	ll m = a[0].size();

	auto temp = a;

	rep(i, n) {
		rep(j, m) {
			temp[i][j] = 0;
		}
	}


	rep(i, n) {
		rep(j, m) {
			rep(k, m) {
				temp[i][j] += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
			}
		}
	}

	a = temp;

	return;
}

void matPow(vvll &mat, ll x, ll mod) {
	if (x == 1) {
		return;
	}
	if (!x) {
		ll n = mat.size();
		ll m = mat[0].size();
		rep(i, n) {
			rep(j, m) {
				mat[i][j] = (i == j);
			}
		}

		return;
	}

	auto temp = mat;

	if (x % 2 == 0) {
		matPow(mat, x / 2, mod);
		matMult(mat, mat, mod);
		return;
	}

	matPow(mat, x - 1, mod);
	matMult(mat, temp, mod);
	return;
}

ll n, k;
vvll a;
void solve() {
	cin >> n >> k;
	vset(a, n, vll(n, 0));
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}

	matPow(a, k, MOD);
	ll ans = 0ll;
	rep(i, n) {
		rep(j, n) {
			ans += a[i][j];
			ans %= MOD;
		}
	}

	ans = (ans % MOD + MOD) % MOD;

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