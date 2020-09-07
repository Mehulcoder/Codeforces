/*
Author: Mehul Chaturvedi
Talent is overrated
*/

/*
* The written solution is wrong. Needs to be corrected.
* The written solution is wrong. Needs to be corrected.
* The written solution is wrong. Needs to be corrected.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;


void solve() {
	ll n, m; cin >> n >> m;
	vll v(n, 0);
	rep(i, n) {
		cin >> v[i];
		if (i != 0) v[i] += v[i - 1];
		v[i] = (m + (m + v[i]) % m) % m;
		if (v[i] == 0) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
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