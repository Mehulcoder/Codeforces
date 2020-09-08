/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main(int argc , char ** argv) {
	ll n; cin >> n;

	vector<int> ans(n, -1);
	set<ll> s;
	rep(i, n) {
		s.insert(i + 1);
	}

	ll a = 0;
	ll b = 1;
	while (a < n && b < n) {
		cout << "? " << a + 1 << " " << b + 1 << endl;
		fflush(stdout);

		ll temp1; cin >> temp1;
		cout << "? " << b + 1 << " " << a + 1 << endl;
		fflush(stdout);

		ll temp2; cin >> temp2;
		if (temp1 > temp2) {
			ans[a] = temp1;
			s.erase(temp1);
		} else {
			ans[b] = temp2;
			s.erase(temp2);
		}

		while (a < n && ans[a] != -1) a++;
		while ((b < n) && (ans[b] != -1 || a == b)) b++;
	}

	rep(i, n) {
		if (ans[i] == -1) ans[i] = (*s.begin());
	}

	cout << "! ";
	rep(i, n) cout << ans[i] << ' ';
	cout << '\n';

	return 0 ;
}