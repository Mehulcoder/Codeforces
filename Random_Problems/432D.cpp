/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

vector<pll> ans;
vll v;

/*
* Calculate Z array in O(n).For every length L from 1 to n-1 if Z[n-L] is L (i.e. prefix==suffix)
* then answer is count of indices for which value of Z array is >= L. Summary of the last line in easy words :
* if the Z value is >= L then obviously the string whose occurrences we need to count is a substring
* of this bigger string
*/

vector<ll> getZArr(string &s) {
	ll l = 0, r = 0;
	ll n = s.size();
	vector<ll> z(n);
	z[0] = s.size();

	// Do not start from i=0. You'll get TLE. Because that
	// initializes our 'r' to n-1 permanently. And makes our
	// l '0'. z[i] will be equal to z[i] always.(Line(44))
	//The algo will become n^2
	fr(i, 1, n - 1) {
		//If i am currently inside the box
		// I can use the previously calculated values
		if (i <= r) {
			//We can only match till the end of the box
			z[i] = min(z[i - l], r - i + 1);
		}
		//We'll use trivial algo to increment the initial values
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		//Update the r of the z box
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	rep(i, n) v.push_back(z[i]);
	sort(all(v));
	return z;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n;
	string s;
	cin >> s;
	n = s.size();
	vector<ll> z = getZArr(s);

	rep(i, n) {
		if (z[i] == n - i) {
			//Found a match
			ll count = v.end() - lower_bound(all(v), z[i]);
			ans.push_back({z[i], count});
		}
	}
	cout << ans.size() << '\n';
	sort(all(ans));
	rep(i, ans.size()) {
		cout << ans[i].f << " " << ans[i].s << '\n';
	}

	return 0 ;
}