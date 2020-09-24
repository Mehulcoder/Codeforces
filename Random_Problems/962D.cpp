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
#define trav(a, x) for(auto &a : x)

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;
	vll a(n, 0);

	rep(i, n) cin >> a[i];

	map<ll, set<ll>> m;
	rep(i, n) {
		m[a[i]].insert(i);
	}

	trav(elem, m) {
		ll curr = 0;
		ll sz = (elem.s).size();

		while (1) {
			if ((curr == sz - 1 && sz % 2 != 0) || (curr == sz && sz % 2 == 0)) break;

			auto ind = *((elem.s).begin());

			if (curr % 2 != 0) m[2 * (elem.f)].insert(ind);
			(elem.s).erase(ind);
			curr++;
		}
	}

	vll ans(n, -1), anss;
	trav(elem, m) {
		if (elem.s.size() == 1)
			ans[*((elem.s).begin())] = elem.f;
	}

	rep(i, n) {
		if (ans[i] != -1) anss.push_back(ans[i]);
	}

	cout << anss.size() << '\n';
	rep(i, anss.size()) {
		cout << anss[i] << ' ';
	}
	cout <<  '\n';

	return 0 ;
}