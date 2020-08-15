/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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


const ll N = 5e6 + 10;
vector<vll> dp;
vector<pll> v;

ll get(ll end, ll state) {
	if (end == 0) return 0;

	ll &ans = dp[state][end];
	if (ans != -1) return ans;

	if (state == 1) {
		if (v[end].f - v[end].s <= v[end - 1].f) ans = 0ll;
		else {
			ans = 1 + max(get(end - 1, 1), get(end - 1, 0));
			if (v[end - 1].f + v[end - 1].s + v[end].s < v[end].f) ans = max(ans, 1 + get(end - 1, 2));
		}
	}

	if (state == 2) {
		if (v[end].f + v[end].s >= v[end + 1].f) ans =  0ll;
		else {
			ans = 1 + max(get(end - 1, 0), get(end - 1, 1));
			if (v[end - 1].f + v[end - 1].s < v[end].f) ans = max(ans, 1 + get(end - 1, 2));
		}
	}

	if (state == 0) {
		ans = max(ans, get(end - 1, 0), get(end - 1, 1));
		if (v[end - 1].f + v[end - 1].s < v[end].f) ans = max(ans, get(end - 1, 2));
	}

	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	v.resize(n);
	rep(i, n) {
		ll a, b; cin >> a >> b;
		v[i] = {a, b};
	}

	rep(i, n) {

	}

	v.push_back({INF / 2, 0});
	v.push_back({ -INF / 2, 0});

	sort(all(v));
	dp.resize(3, vll(n + 2, -1));

	cout << max({get(n, 0), get(n, 1), get(n, 2)}) << '\n';

	return 0 ;
}

