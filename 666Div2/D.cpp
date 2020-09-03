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
* https://youtu.be/ccgf2oAeEWc?t=7318
* If a[i]>s/2 you can always choose that pile
* and others will eventually just get used up
* But a[i] still will be left with atleast 1. You win.

* Otherwise you'll always try to choose the max height.
* Take some examples for this case, you'll get the intuition
* If someone could mathematcally explain me the second case.
* DM me.
*/

void solve() {
	ll n; cin >> n;
	vll a(n);

	ll sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}

	rep(i, n) {
		if (a[i] > sum / 2) {
			cout << "T" << '\n';
			return;
		}
	}

	if (sum % 2 == 0) {
		cout << "HL" << '\n';
	} else {
		cout << "T" << '\n';
	}

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