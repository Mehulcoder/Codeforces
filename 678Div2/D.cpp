/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)


const ll N = 2e5 + 10;

ll n;
vll edges[N];
vll citizens;

ll ceel(ll a, ll b) {
	if (!(a % b)) {
		return a / b;
	}
	return a / b + 1;
}

//Max, leaves, canTake
vll dfs(ll root) {
	if (!edges[root].size()) {
		return {citizens[root], 1, 0};
	}

	ll maxi = 0;
	ll lv = 0;
	vvll v;
	trav(child, edges[root]) {
		auto temp = dfs(child);
		maxi = max(maxi, temp[0]);
		lv += temp[1];
		v.push_back(temp);
	}

	ll curr = citizens[root];
	ll canTake = 0;
	trav(elem, v) {
		canTake += elem[2] + (maxi - elem[0]) * elem[1];
	}

	if (canTake >= curr) {
		canTake = canTake - curr;
		curr = 0;
	} else {
		curr -= canTake;
		canTake = 0;
	}
	if (curr > 0) {
		ll oldMaxi = maxi;
		ll IncInAll = curr / lv;
		ll incInFew = ceel(curr, lv);
		maxi += incInFew;
		ll cntMaxi = curr % lv;
		if (!cntMaxi) cntMaxi = lv;

		canTake += lv - cntMaxi;
	}


	return {maxi, lv, canTake};

}

void solve() {
	cin >> n;
	citizens.resize(n, 0);
	rep(i, n - 1) {
		ll p; cin >> p;
		p--;
		edges[p].push_back(i + 1);
	}

	rep(i, n) cin >> citizens[i];

	auto ans = dfs(0);
	cout << ans[0] << '\n';
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