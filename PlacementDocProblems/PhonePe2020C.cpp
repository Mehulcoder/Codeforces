/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* x and y are <= 1e12, that means the count of their parent+parent's parent + .... + root
* is less than equal to log_N(1e12) <= 40. So we can store the ancestors of both the vertices
* till, the root(0). And check what part is common from the end between both of them. If
* we remove that common part then, the remaining elements' count will be the answer

* Also, it can easily be seen that the child of the node named i are : in+1, in+2...in+n
* So the parent of the node j will be (j-1)/n. (0 based index)
*/

ll n, x, y;
void solve() {
	cin >> n >> x >> y;
	x--; y--;

	if (x < y) swap(x, y);
	//X is the greater one now

	ll parx = x;
	ll pary = y;

	vll a, b;
	bool flaga = 0, flagb = 0;
	while (1) {
		if (!flaga) {
			a.push_back(parx);
			if (parx == 0) flaga = 1;
		}
		if (!flagb) {
			b.push_back(pary);
			if (pary == 0) flagb = 1;
		}

		parx = (parx - 1) / n;
		pary = (pary - 1) / n;

		if (flaga && flagb) break;
	}


	ll i = a.size() - 1;
	ll j = b.size() - 1;

	while (1) {
		if (a[i] != b[j]) {
			cout << i + j + 2 << '\n';
			return;
		}
		i--;
		j--;
	}

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