/*
Author: Mehul Chaturvedi
Talent is overrated
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
	ll n; cin >> n;
	vll a(n, 0);
	rep(i, n) cin >> a[i];

	ll c0 = 0, c1 = 0;
	rep(i, n) {
		if (a[i] == 0) c0++;
		else c1++;
	}

	if (c0 < c1) {
		if (c1 % 2 != 0)c1--;
		cout << c1 << '\n';
		rep(i, c1) {
			cout << 1 << ' ';
		}
		cout << '\n';
	} else {
		cout << c0 << '\n';
		rep(i, c0) {
			cout << 0 << ' ';
		}
		cout << '\n';
	}

	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}