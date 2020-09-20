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

/*
* Keep elements in decreasing order keeping a gap of one index
* Keep remaining at the gaps in the inc order.
*/

void solve() {
	ll n; cin >> n;
	vll a(n, 0);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vll temp(n, -1);

	ll curr = 0;
	fr(i, n / 2, n - 1) {
		temp[curr] = a[i];
		curr += 2;
	}

	curr = 1;
	rep(i, n / 2) {
		temp[curr] = a[i];
		curr += 2;
	}

	cout << (n - 1) / 2 << '\n';
	rep(i, n) {
		cout << temp[i] << ' ';
	}
	cout << '\n';

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