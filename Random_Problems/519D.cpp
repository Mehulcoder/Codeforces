/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)


int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	vll val(26, 0);
	vvll pos(26, vll(0));

	rep(i, 26) cin >> val[i];
	string s; cin >> s;
	ll n = s.size(), ans = 0ll;
	vll pre(n, 0);

	rep(i, n) {
		pos[s[i] - 'a'].push_back(i);
		pre[i] = val[s[i] - 'a'];
		if (i > 0) pre[i] += pre[i - 1];
	}

	rep(c, 26) {
		map<ll, ll> m;
		trav(p, pos[c]) {
			if (p > 0) {
				ll preSum = pre[p - 1];
				ans += m[preSum];
			}
			m[pre[p]]++;
		}
	}
	cout << ans << '\n';

	return 0 ;
}