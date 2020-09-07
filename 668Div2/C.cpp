/*
Author: Mehul Chaturvedi
Talent is overrated
*/

/*
* WTFFF, how could you read 2 questions in one contest wrongly
* Press F. RIP ratings
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


/*
* Easy logic: The string has an interval k
*/

ll k, n;
string s;
bool check(ll start) {
	for (int i = start; i < n && i < start + k; ++i) {
		if (s[i] == '?') continue;
		if (s[i] == '0') {
			if (s[i % k] == '?' || s[i % k] == '0') {
				s[i % k] = '0';
			} else {
				return 0;
			}
		} else {
			if (s[i % k] == '?' || s[i % k] == '1') {
				s[i % k] = '1';
			} else {
				return 0;
			}

		}
	}

	return 1;
}

void solve() {
	cin >> n >> k;
	cin >> s;

	for (int i = k; i < n; i += k) {
		if (!check(i)) {
			cout << "NO" << '\n';
			return;
		}
	}

	ll c1 = 0;
	ll c2 = 0;
	ll c3 = 0;
	rep(i, k) {
		if (s[i] == '0') c1++;
		else if (s[i] == '1') c2++;
		else if (s[i] == '?') c3++;
	}

	c1 = min(c1, c2);
	ll req = k / 2 - c1;
	if (c3 < req) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
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