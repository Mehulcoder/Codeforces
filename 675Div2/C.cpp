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

class node {
public:
	ll ans;
	ll suffRem;
	ll times;
	ll prevNum;

	node(ll a, ll s, ll t, ll p) {
		ans = a;
		suffRem = s;
		times = t;
		prevNum = p;
	}
};

string s;
node get(ll end) {
	if (end == 0ll) {
		return node(s[0] - '0', s[0] - '0', 2, s[0] - '0');
	}

	auto prev = get(end - 1);

	//Do not remove last element
	ll anss = (prev.ans * 10 + prev.times * (s[end] - '0')) % MOD;

	//Now remove the last element with others along it maybe
	anss += prev.suffRem;

	ll timess = (prev.times + end + 1) % MOD;

	ll suffRemm = prev.suffRem;
	ll temp = prev.prevNum;
	temp = (temp * 10 + s[end] - '0') % MOD;

	suffRemm += temp + MOD;
	suffRemm %= MOD;

	return node(anss, suffRemm, timess, temp);

}
void solve() {
	cin >> s;
	ll n = s.size();
	auto temp = get(n - 1);
	ll tempp = 0ll;
	rep(i, n) {
		tempp = (tempp * 10 + (s[i] - '0')) % MOD;
	}

	cout << ((temp.ans - tempp) % MOD + MOD) % MOD << '\n';
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