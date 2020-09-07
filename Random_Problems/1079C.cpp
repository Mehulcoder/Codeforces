#include <bits/stdc++.h>
using namespace std;

bool ok(int a1, int a2, int b1, int b2) {
	return (a1 < a2 && b1 < b2) || (a1 > a2 && b1 > b2) || (a1 == a2 && b1 != b2);
}

int A[100000], dp[100000][5];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	memset(dp, -1, sizeof(dp));
	for (int j = 0; j < 5; j++) dp[0][j] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[i][j] == -1) continue;
			for (int k = 0; k < 5; k++) {
				if (ok(A[i], A[i + 1], j, k)) dp[i + 1][k] = j;
			}
		}
	}
	for (int j = 0; j < 5; j++) {
		if (dp[N - 1][j] >= 0) {
			vector<int> ans(N);
			int num = j;
			for (int i = N - 1; i >= 0; i--) {
				ans[i] = num + 1;
				num = dp[i][num];
			}
			for (int i = 0; i < N; i++) {
				cout << ans[i] << " \n"[i == N - 1];
			}
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}