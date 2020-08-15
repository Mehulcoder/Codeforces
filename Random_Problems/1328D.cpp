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
* Ans could be at max 3. If all same:1
* If even n: 2 (place alternate 1212..)
* If odd and in case you find to consec equal(or 0 and n-1 equal)
* 121212122111.. pattern right to that location can be switched: 2
* If odd and no consec equal: 3
* NOTE: You need not to color same animals same. It is not a must.
*/

void solve() {
	ll n; cin >> n;
	vll v(n, 0), ans(n, 3);
	rep(i, n) cin >> v[i];

	ll eqCount = 0, type = 3;
	if (v[0] == v[n - 1]) eqCount++;
	rep(i, n) {
		if (i != 0 && v[i] == v[i - 1]) eqCount++;
	}
	if (v[0] == v[n - 1] && type == 3) type = 2;

	ll Ans = 3;
	if (eqCount == n) Ans = 1, type = 1;
	else if (n % 2 == 0 || eqCount > 0) Ans = 2, type = 2;

	if (type == 1) {
		rep(i, n) ans[i] = 1;
	} else if (type == 2 && n % 2 == 0)
	{
		rep(i, n) ans[i] = (i % 2 + 1);
	} else if (type == 2 && n % 2 != 0)
	{
		ll changePos = -1;
		rep(i, n) {
			if (i != 0 && v[i] == v[i - 1]) {
				changePos = i;
				break;
			}
		}
		rep(i, changePos) {
			ans[i] = (i % 2 + 1);
		}
		fr(i, changePos, n - 1) ans[i] = (!(i % 2) + 1);
	} else if (type == 3)
	{
		rep(i, n - 1) ans[i] = (i % 2 + 1);
	}

	cout << Ans << '\n';
	trav(elem, ans) cout << elem << ' ';
	cout << '\n';
	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}