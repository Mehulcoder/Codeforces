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
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* We can change the element a of the array to a%x+k*x
* And all the elements of the form ai%x+k*x can be uniquely
* formed by only and only ai and none else.

* Store the frequency of each (ai%x) in the array.
* The one which has minimum freq (if multiple minimum, the
* one with a lesser value of ai%x is chosen) will exhaust
* first and the element with the value ai%+x*freq[ai%x] will
* be missing(Only ai%x can lead to the formation of this number)
* So it will be the MEX
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll q, x; cin >> q >> x;

	vll mods(x + 1, 0);
	set<pll> s;

	rep(i, x) {
		s.insert({0, i});
	}

	ll mex = 0;
	while (q--) {
		ll a; cin >> a;
		a %= x;
		if (s.find({mods[a], a}) != s.end()) {
			s.erase({mods[a], a});
		}
		mods[a]++;
		s.insert({mods[a], a});
		mex = (*s.begin()).s + x * (*s.begin()).f;
		cout << mex << '\n';
	}

	return 0 ;
}