#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


void solve() {
	ll n; cin >> n;
	string s; cin >> s;

	ll v = 0;
	rep(i, n) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') v++;
	}

	if (v > 1) {
		cout << "D" << '\n';
	} else {
		if (v == 0) {
			if (n % 2 == 0) {
				cout << "B" << '\n';
			} else {
				cout << "A" << '\n';
			}
		} else {
			if (n % 2 != 0) {
				cout << "D" << '\n';
			} else if (n % 2 == 0) {
				cout << "A" << '\n';
			}
		}
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