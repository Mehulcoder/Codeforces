/*
Author: Mehul Chaturvedi
Talent is overrated
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
const ll N = 2e5 + 10;

ll v[N] = {0};
ll ans = 0;
map<ll, ll> m1, m2;
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, k; cin >> n >> k;
	rep(i, n) {
		cin >> v[i];
		if (v[i] % k == 0) {
			ans += m2[v[i] / k];
			m2[v[i]] += m1[v[i] / k];
		}
		m1[v[i]]++;
	}

	cout << ans << '\n';
	return 0 ;
}
