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
* If all same as x ==> 0

* If one same as x or sum of diff of all from x == 0 ==> 1

* Can always do it in two: Make one same as infected ---> Now
* use that infected as a donor/acceptor of points from others
* so that they can achieve the infection in one more step ===> 2
*/

void solve() {
	ll n, x; cin >> n >> x;

	vll a(n, 0);
	bool flag = 1;
	bool flag2 = 0;
	ll sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += (x - a[i]);
		if (a[i] == x) flag2 = 1;
		if (a[i] != x) flag = 0;
	}

	if (flag) {
		cout << 0 << '\n';
	} else if (!sum || flag2) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
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