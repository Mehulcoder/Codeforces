#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<char> calced(n);
	vector<string> a(n);
	set<string> have;
	int res = 0;

	for (string &pin : a) {
		cin >> pin;
		have.insert(pin);
	}

	for (int i = 0; i < n; i++) {
		if (calced[i]) {
			continue;
		}

		vector<int> sameIds;

		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				sameIds.push_back(j);
				calced[j] = 1;
				res++;

				for (int k = 0; k < 4 && a[i] == a[j]; k++) {
					for (char c = '0'; c <= '9'; c++) {
						string t = a[j];
						t[k] = c;

						if (!have.count(t)) {
							have.insert(t);
							a[j] = t;
							break;
						}
					}
				}
			}
		}
	}

	cout << res << "\n";

	for (string& s : a) {
		cout << s << "\n";
	}
}

int main() {
	int test;
	cin >> test;

	while (test--) {
		solve();
	}
}