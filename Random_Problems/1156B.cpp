/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* Answer is basically consecutive addition of
* alphabets in the string which are at even and
* at odd positions in the character table.
* Treat group of same characters as a single one.
* If such arrangement fails the check: No answer.
*/

bool check(string s) {
	rep(i, s.size() - 1) {
		if (abs(s[i] - s[i + 1]) == 1) return 0;
	}

	return 1;
}

void solve() {
	string s; cin >> s;
	ll n = s.size();

	vll e, o;
	map<ll, ll> m;
	rep(i, s.size()) {
		if (m.find(s[i] - 'a') == m.end()) {
			if ((s[i] - 'a') % 2 == 0) {
				e.push_back(s[i] - 'a');
			} else {
				o.push_back(s[i] - 'a');
			}
		};

		m[s[i] - 'a']++;
	}

	sort(all(e));
	sort(all(o));

	string even, odd;
	rep(i, e.size()) {
		ll count = m[e[i]];
		even += string(count, (e[i] + 'a'));
	}
	rep(i, o.size()) {
		ll count = m[o[i]];
		odd += string(count, (o[i] + 'a'));
	}


	if (check(even + odd)) {
		cout << even + odd << '\n';
	} else if (check(odd + even)) {
		cout << odd + even << '\n';
	} else {
		cout << "No answer" << '\n';
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