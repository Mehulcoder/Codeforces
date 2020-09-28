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
const ll MOD = 1e9 + 9;

/*
* Maximum is easy. Let's look into minimum.
* Say you choose stone, you'd want opponent to choose
* Scissor, as much as possible(you won't stop inbetween)
* Or would want him to choose stone, as much possible
* That "as much as possible" can have different permutations
* Just brute force all the 720 permutations and get the mini.
* Boom!!! That was easy!
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	ll ansMin = INF, ansMax = 0;

	vll a(3), b(3);

	rep(i, 3) cin >> a[i];
	rep(i, 3) cin >> b[i];


	vector<pll> orders;
	orders.push_back({0, 0});
	orders.push_back({0, 2});
	orders.push_back({1, 1});
	orders.push_back({1, 0});
	orders.push_back({2, 1});
	orders.push_back({2, 2});

	sort(all(orders));

	do {
		vll a1, b1;
		a1 = a; b1 = b;

		trav(match, orders) {
			ll temp = min(a1[match.f], b1[match.s]);
			a1[match.f] -= temp;
			b1[match.s] -= temp;
		}

		ll currWins = min(a1[0], b1[1]) + min(a1[2], b1[0]) + min(a1[1], b1[2]);
		ansMin = min(ansMin, currWins);

	} while (next_permutation(all(orders)));


	ansMax = min(a[0], b[1]) + min(a[2], b[0]) + min(a[1], b[2]);
	cout << ansMin << " " << ansMax << '\n';


	return 0 ;
}