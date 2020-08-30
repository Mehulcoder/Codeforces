/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


/*
* Make them all divisible by n before the final step
* Take first n-1 elements add a[i]*(n-1) to them
* Take the last element add n-a[i] to it
* In the last step add -a[i] to each
*/

/*
* PS: I hate Adhoc
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	vll v(n, 0);
	rep(i, n) cin >> v[i];

	if (n == 1) {
		cout << 1 << " " << n  << '\n';
		cout << -v[0] << '\n';
		rep(i, 2) {
			cout << 1 << " " << n  << '\n';
			cout << 0  << '\n';
		}
	}


	if (n > 1) {
		cout << 1  << " " << n - 1 << '\n';

		rep(i, n - 1) {
			cout << v[i] * (n - 1) << ' ';
			v[i] += v[i] * (n - 1);
		}

		cout << '\n';

		cout << n  << " " << n  << '\n';
		cout << -v[n - 1] << '\n';

		v[n - 1] = 0;


		cout << 1 << " " << n  << '\n';
		rep(i, n) {
			cout << -v[i] << ' ';
		}

		cout << '\n';
	}


	return 0 ;
}