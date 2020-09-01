/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)

/*
* https://codeforces.com/blog/entry/64439?#comment-483452
*/

void solve() {
	ll n; cin >> n;
	string s; cin >> s;

	vll cnt(3, 0);
	rep(i, n) cnt[s[i] - '0']++;

	ll start = 0;
	while (cnt[0] < n / 3) {
		if (cnt[s[start] - '0'] > n / 3) {
			cnt[s[start] - '0']--;
			s[start] = '0';
			cnt[0]++;
		}
		start++;
	}

	start = n - 1;
	while (cnt[2] < n / 3) {
		if (cnt[s[start] - '0'] > n / 3) {
			cnt[s[start] - '0']--;
			s[start] = '2';
			cnt[2]++;
		}
		start--;
	}


	start = 0;
	while (cnt[1] < n / 3 && start < n) {
		if (s[start] == '2' && cnt[2] > n / 3) {
			cnt[2]--;
			cnt[1]++;
			s[start] = '1';
		}
		start++;
	}

	start = n - 1;
	while (cnt[1] < n / 3) {
		if (s[start] == '0' && cnt[0] > n / 3) {
			cnt[0]--;
			cnt[1]++;
			s[start] = '1';
		}
		start--;
	}
	cout << s << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0 ;
}