

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	bool bw = 1, wb = 0;
	int b = 1, w = 1;
	int i = 0;
	for (auto &elem : s) {
		i++;
		char c = ((i % 2 == 0) ? 'W' : 'B');
		if (elem == 'R') {
			if (c == 'W') {
				if (bw == 1) {
					w++;
					wb = 0;
				} else {
					b = 0;
					w = i + 2;
					bw = 1;
					wb = 1;
				}
			} else {
				if (wb == 1) {
					bw = 0;
					b++;
				} else {
					w = 0;
					b = i + 2;
					wb = 1;
					bw = 1;
				}
			}
		} else {
			if (c == 'W') {
				if (wb == 1) {
					w++;
					bw = 0;
				} else {
					b = 0;
					w = i + 2;
					wb = 1;
					bw = 1;
				}
			} else {
				if (bw == 1) {
					b++;
					wb = 0;
				} else {
					b = i + 2;
					w = 0;
					bw = 1;
					wb = 1;
				}
			}
		}
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