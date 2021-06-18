
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
vll a;
vvll ans;

void get(ll i) {
	ll val = a[i] - 1;
	ll r = i;
	ll c = i;
	while (val--) {
		ll r1 = r;
		ll c1 = c - 1;

		if (c1 >= 0 && ans[r1][c1] == -1) {
			ans[r1][c1] = a[i];
			c--;
		} else {
			ans[r + 1][c] = a[i];
			r++;
		}
	}

	return;
}
void solve() {
	a.clear();
	ans.clear();

	cin >> n;
	a.resize(n);
	ans.resize(n, vll(n, -1));
	rep(i, n) cin >> a[i];

	rep(i, n) {
		ans[i][i] = a[i];
		get(i);
	}

	rep(i, n) {
		rep(j, i + 1) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

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