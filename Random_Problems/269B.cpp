/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define INF 4557430888798830399ll
#define all(x) (x).begin(), (x).end()
const ll N = 1e4;

ll s[N];
ll n, m;

/*
* Simple LIS problem, can be done in O(nlogn) using
* tail method. A  really nice approach explained nicely
* on Leetcode and GFG.

* PS: Trying to make my code template free and clean
* PS: Quick reminder to get back to Leetcode. It has nice
* algorithms. Less Adhoc. Less fun though.
*/

ll getLis() {
	vector<ll> list;
	list.push_back(-INF);

	for (int i = 0; i < n; ++i) {
		if (s[i] >= list.back()) {
			list.push_back(s[i]);
		} else {
			ll ind = upper_bound(all(list), s[i]) - list.begin();
			list[ind] = s[i];
		}
	}

	return list.size() - 1;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		ld temp; cin >> temp;
	}

	cout << n - getLis() << endl;

	return 0 ;
}