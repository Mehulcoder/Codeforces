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


void solve() {
	unsigned int seed;
	cin >> seed;
	srand(seed);
	ll k = rand();
	k = k % 10 + 1;
	while (k--) {
		ll num = rand();
		num = (num % 10001) + 1;

		ll count = rand();
		count = count % 10 + 1;

		cout << num << ' ' << count << endl;;

		vll a;
		rep(i, count) {
			//from 0-count-1
			a.push_back(i);
		}

		shuffle(all(a), default_random_engine(seed));

		rep(i, count) cout << a[i] << " ";
		cout << endl;
	}

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