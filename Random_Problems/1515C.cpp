
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

/**
 * Simply put the smallest blocks in the tower which has the smallest
 * height yet. Do this and check in the last that if the conditon of
 * x has been satisfied.
 */


void solve(int  t) {
	ll n, m, x; cin >> n >> m >> x;

	vector<pair<ll, ll>> h(n);
	rep(i, n) {
		cin >> h[i].f;
		h[i].s = i;
	}

	set<pair<ll, ll>> bucket;
	rep(i, m) {
		bucket.insert({0, i + 1});
	}

	sort(all(h));
	vector<ll> ans(n);

	rep(i, n) {
		auto temp = *bucket.begin();
		bucket.erase(bucket.begin());
		temp.f += h[i].f;
		ans[h[i].s] = temp.s;
		bucket.insert(temp);
	}

	ll mini, maxi;
	mini = (*bucket.begin()).f;
	trav(elem, bucket) {
		maxi = elem.f;
	}


	if (maxi - mini > x) {
		cout << "NO" << endl;
		return;
	} else {
		cout << "YES" << endl;
	}
	rep(i, n) {
		cout << ans[i] << " ";
	}

	cout << endl;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve(t);
	}

	return 0 ;
}