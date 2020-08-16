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
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


void solve() {
	ll n; cin >> n;
	vector<pll> v(n), v1, v2;
	vll temp1, temp2;
	rep(i, n) {
		cin >> v[i].f >> v[i].s;
		if (v[i].f < v[i].s) v1.push_back({v[i].s, i});
		else if (v[i].f > v[i].s) v2.push_back({v[i].s, i});
	}

	// Case1: a<b>a
	sort(all(v1), greater<pll>());
	ll ans1 = 0, ans2 = 0, curr1 = INF, curr2 = -INF;
	rep(i, v1.size()) {
		if (v[v1[i].s].f < curr1) {
			ans1++;
			curr1 = v1[i].f;
			temp1.push_back(v1[i].s);
		}
	}

	//Case2: a>b<a
	sort(all(v2));
	rep(i, v2.size()) {
		if (v[v2[i].s].f > curr2) {
			ans2++;
			curr2 = v2[i].f;
			temp2.push_back(v2[i].s);
		}
	}

	if (ans1 < ans2)swap(temp1, temp2);
	cout << temp1.size() << '\n';
	rep(i, temp1.size()) {
		cout << temp1[i] + 1 << ' ';
	}
	cout << '\n';
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