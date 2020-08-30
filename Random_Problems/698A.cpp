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


vll v;
ll dp[105][4];
ll get(ll end, ll state) {
	if (end < 0) return 0;
	ll val = v[end];

	ll &ans = dp[end][state];
	if (ans != -1) return ans;

	ans = INF;
	if (state == 0) {
		//Take rest now, iske pehle kuch bhi
		rep(i, 3) {
			ans = min(ans, 1 + get(end - 1, i));
		}
		return ans;
	} else if (state == 1) {
		//val should be 2 or 3
		if (val != 2 && val != 3) return ans = INF;
		else {
			return ans = min(get(end - 1, 2), get(end - 1, 0));

		}
	} else {
		//val should be 2 or 3
		if (val != 1 && val != 3) return ans = INF;
		else {
			return ans = min(get(end - 1, 1), get(end - 1, 0));
		}

	}

	return INF;
}

/*
* 0: Rest
* 1: Gym
* 2: code
*/
void solve() {
	fil(dp, -1);
	ll n; cin >> n;
	vset(v, n, 0);
	rep(i, n) cin >> v[i];

	ll ans = INF;
	rep(i, 3)ans = min(ans, get(n - 1, i));
	cout << ans << '\n';
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