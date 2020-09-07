/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* WTFFF, how could you read 2 questions in one contest wrongly
* Press F
*/

ll n;
void solve() {
	cin >> n;
	vector<ll> a(n, 0);
	rep(i, n) cin >> a[i];

	reverse(a.begin(), a.end());
	rep(i, n) cout << a[i] << ' ';

	cout << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}