/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
const ll MOD = 1e9 + 9;

vll a;
ll get(ll left, ll right, ll offset) {
	if (left > right) return 0;

	ll minInd = min_element(a.begin() + left, a.begin() + right + 1) - a.begin();
	ll minHeight = a[minInd];

	ll cost = minHeight - offset + get(left, minInd - 1, minHeight) + get(minInd + 1, right, minHeight);
	return cost = min(right - left + 1, cost);
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;

	vset(a, n, 0);
	rep(i, n) cin >> a[i];

	cout << get(0, n - 1, 0) << '\n';

	return 0 ;
}