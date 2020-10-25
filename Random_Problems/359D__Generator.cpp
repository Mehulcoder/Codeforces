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


ll getNum(ll from, ll to) {
	assert(from <= to);
	ll num = (ll)rand();
	num %= (to - from + 1);
	num += from;
	return num;
}

vector<ll> getArray(ll from, ll to, ll sz) {
	assert(from <= to && sz > 0);

	vector<ll> ans;
	ans.resize(sz);

	rep(i, sz) {
		ans[i] = getNum(from, to);
	}

	return ans;
}


void getTestCases() {
	ll n = getNum(1, 4000);
	cout << n << '\n';
	vll uarr = getArray(1, 1000000, n);
	rep(i, uarr.size()) {
		cout << uarr[i] << ' ';
	}
	cout <<  '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	unsigned int seed;
	cin >> seed;
	srand(seed);

	getTestCases();

	return 0 ;
}