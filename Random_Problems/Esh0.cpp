
/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
#define INF 4557430888798830399ll

vector<ll> dp;
ll get(vector<ll> &h, ll start, ll c) {
	ll n = h.size();

	if (start == n - 1) {
		return 0;
	}
	if (dp[start] != -1) {
		return dp[start];
	}

	ll ans = INF;
	for (int i = start + 1; i < n; ++i) {
		ans = min(ans, (h[i] - h[start]) * (h[i] - h[start]) + c + get(h, i, c));
	}

	return dp[start] = ans;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, c; cin >> n >> c;
	vector<ll> h(n, 0);
	dp.clear();
	dp.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	cout << get(h, 0, c);
	return 0 ;
}