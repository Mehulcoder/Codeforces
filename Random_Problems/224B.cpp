/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;
/*
* Find the first eligible segment. Mainatain map of freq
* If total freq till now is equal to k. Tryto reduce span:
* Start from left. Iterate from l and increase it while
* doing m[a[l]]-- till m[a[l]]>1.
*/


void solve() {
	int n, k;
	cin >> n >> k;
	int a[n], l = 0, cnt = 0;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = x;
		if (mp[x] == 0) cnt++;
		if (cnt == k) {
			while (l + 1 <= i && mp[a[l]] > 1) {
				mp[a[l]]--;
				l++;
			}
			cout << l + 1 << " " << i + 1 << endl;
			return;
		}
		mp[x]++;
	}
	cout << -1 << " " << -1;

	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t = 1;

	while (t--) {
		solve();
	}

	return 0 ;
}