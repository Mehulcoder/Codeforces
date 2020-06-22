#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[555];
bool edge[555][555];
char ans[555];
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		edge[x][y] = edge[y][x] = 1;
		cnt[x]++;
		cnt[y]++;
	}
	for (int i = 0; i < n; ++i) {
		if (cnt[i] == n - 1)
			ans[i] = 'b';
	}
	for (int i = 0; i < n; ++i) {
		if (!ans[i]) {
			ans[i] = 'a';
			for (int j = 0; j < n; ++j) {
				if (!ans[j]) {
					if (edge[i][j])
						ans[j] = 'a';
					else
						ans[j] = 'c';
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if ((abs(ans[i] - ans[j]) == 2 && edge[i][j]) || (abs(ans[i] - ans[j]) < 2 && !edge[i][j])) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes\n" << ans << endl;
	return 0;
}