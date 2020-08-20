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


vector<string> m = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<vector<ll>> dp;
vector<string> v;
vll dig;
ll n, k;

/*
* dp[i][j] represents if it is possible change the ith digit
* to some maximum feasible value. If yes then it stores to what value
* Otherwise it has -1. Initial dp state is -2. Make sure to choose the
* maximum value from left to right. Because maximizing left digits maximizes
* the answer
*/

ll toMake(string &from, ll too) {
	string to = m[too];
	ll cost = 0;
	rep(i, 7) {
		if (to[i] == '0' && from[i] == '1') return INF;
		if (to[i] == '1' && from[i] == '0') cost++;
	}

	return cost;
}

ll get(ll start, ll money) {
	if (money < 0) return -1;
	if (start == n - 1) {
		repr(i, 9) {
			ll cost = toMake(v[start], i);
			if (cost == money) {
				dig.push_back(i);
				return i;
			}
		}
		return -1;
	}

	ll &ans = dp[start][money];
	if (ans != -2) {
		if (ans != -1) dig.push_back(ans);
		return ans;
	}

	ans = -1;
	repr(i, 9) {
		ll cost = toMake(v[start], i);

		if (cost <= money) {
			ll temp = get(start + 1, money - cost);
			if (temp != -1) {
				dig.push_back(i);
				ans = i;
				break;
			}
		}
	}

	return ans;
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	rep(i, n) cin >> v[i];
	dp.resize(n + 1, vector<ll>(k + 1, -2));

	ll ans = get(0, k);

	if (ans == -1) cout << -1;
	else repr(i, dig.size() - 1) cout << dig[i];
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