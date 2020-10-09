/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* ..AAABCBC...BC.. Now, k continuous A, and l continuous BC after those A
* Will result in k*l operations. Also note that this will shift those k As
* to the right of all BCs, so keep that buffer count in case you encounter
* As again after the BCs
*/
void solve() {
	string s; cin >> s;
	ll n = s.size();

	ll ans = 0ll;
	ll i = 0ll;
	ll prevA = 0;
	while (i < n) {
		if (s[i] == 'A') {
			ll count = 0ll;
			while (i < n && s[i] == 'A') {
				count++;
				i++;
			}
			count += prevA;
			prevA = count;
			ll count2 = 0ll;
			while (i < n - 1 && s[i] == 'B' && s[i + 1] == 'C') {
				count2++;
				i++;
				i++;
			}

			ans += count * count2;
		} else {
			prevA = 0;
			i++;
		}
	}

	cout << ans << '\n';
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