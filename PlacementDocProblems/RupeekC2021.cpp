/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, sum = 0;
	cin >> n;
	vector<pair<int, string>> v;
	vector<int> pre(n, 0);

	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int wt = 0;
		for (auto &elem : s) wt += elem - 'a' + 1;
		v.push_back({wt, s});
		sum += wt;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		pre[i] = v[i].first;
		if (i != 0) pre[i] += pre[i - 1];
	}


	int ans = INT_MAX;
	string anss = "";

	//Remove last element
	for (int i = 0; i < n - 1; ++i) {
		int cost = sum - v[n - 1].first + v[i].first * (2 * i - n);
		if (i != 0) cost -= 2 * pre[i - 1];

		if (cost < ans) anss = v[i].second;
		ans = min(ans, cost);
	}

	//Remove first element
	for (int i = 1; i < n; ++i) {
		int cost = sum + v[0].first + v[i].first * (2 * i - n);
		if (i != 0) cost -= 2 * pre[i - 1];

		if (cost < ans) anss = v[i].second;
		ans = min(ans, cost);
	}

	cout << anss << '\n';
	return;
}

int main(int argc , char ** argv) {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}