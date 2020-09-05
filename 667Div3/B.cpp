/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;

	//Apply on  a
	ll A = max(a - n, x);
	ll left = n - (a - A);
	ll B = max(b - left, y);
	ll prod1 = A * B;

	//Apply on  b
	B = max(b - n, y);
	left = n - (b - B);
	A = max(a - left, x);
	ll prod2 = A * B;

	cout << min(prod1, prod2) << '\n';
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