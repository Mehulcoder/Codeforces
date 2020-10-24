

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	string ans;
	ans.push_back('B');
	ans.push_back('W');

	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if ((i + 1) % 2 == 0) {
			if (s[i] == 'L') {
				ans.insert(0, "W");
			} else {
				ans.push_back('W');
			}
		} else {
			if (s[i] == 'L') {
				ans.insert(0, "B");
			} else {
				ans.push_back('B');
			}
		}
		if (s[i] == 'L') {
			int ind = -1;
			for (int j = 1; j < ans.size(); ++j) {
				if (ans[j] == ans[0]) {
					ind = j;
					break;
				}
			}
			if (ind != -1) {
				for (int j = 0; j < ind + 1; ++j) {
					ans[j] = ans[0];
				}
			}
		} else {
			int ind = -1;
			for (int j = ans.size() - 2; j >= 0; --j) {
				if (ans[j] == ans.back()) {
					ind = j;
					break;
				}
			}
			if (ind != -1) {
				for (int j = ans.size() - 1; j >= ind; --j) {
					ans[j] = ans.back();
				}
			}
		}
	}
	int b = 0, w = 0;
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] == 'B')b++;
		else w++;
	}
	cout << b << " " << w << '\n';
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