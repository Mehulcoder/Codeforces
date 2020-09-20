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
* n is even: even guy gets the last chance: should have atleast one even to win
* n is odd: odd guy gets the last chance: should have atleast one odd to win
*/

void solve() {
	ll n; cin >> n;
	string s;
	cin >> s;
	vll temp;
	temp.push_back(-1);
	trav(elem, s) {
		temp.push_back(elem - '0');
	}
	n = temp.size() - 1;
	ll o1 = 0;
	ll e1 = 0;
	ll e2 = 0;
	ll o2 = 0;

	fr(i, 1, n) {
		if (i % 2 == 0) {
			if (temp[i] % 2 == 0) e2++;
			else o2++;
		} else {
			if (temp[i] % 2 == 0) e1++;
			else o1++;
		}
	}


	if (n % 2 == 0) {
		if (e2 != 0) {
			cout << 2 << '\n';
		} else {
			cout << 1 << '\n';
		}
	} else {
		if (o1 != 0) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
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