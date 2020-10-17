/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll findMinimumAdjacentSwaps(vector<ll> &arr, ll N) {
	bool visited[N + 1];

	ll minimumSwaps = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		ll count = 0;
		bool flag = 0;
		for (int j = i + 1; j < N; ++j) {
			if (visited[j]) continue;
			if (arr[j] == arr[i]) {
				visited[j] = 1;
				minimumSwaps += count;
				flag = 1;
				break;
			} else {
				count++;
			}
		}

		if (!flag) {
			visited[N - 1] = 1;
			minimumSwaps += count;
		}
	}

	return minimumSwaps;
}


void solve() {
	ll n; cin >> n;

	vector<ll> a;
	a.resize(n);

	map<ll, ll> freq;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		freq[a[i]]++;
	}

	ll notEvenFreq = 0, k = 0;
	map<ll, ll> m;
	for (auto &elem : freq) {
		if (elem.second % 2 != 0) notEvenFreq++;
		m[elem.first] = k++;
	}

	if (notEvenFreq > n % 2) {
		cout << -1 << '\n';
		return;
	}

	for (ll i = 0; i < a.size(); ++i) {
		a[i] = m[a[i]];
	}

	ll ans = findMinimumAdjacentSwaps(a, n);

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