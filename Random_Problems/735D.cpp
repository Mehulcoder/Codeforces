#include<bits/stdc++.h>
using namespace std;
int prime(int N) {
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0)
			return 0;
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	if (prime(N))
		cout << 1;
	else if (N % 2 == 0 || prime(N - 2))
		cout << 2;
	else
		cout << 3;
	cout << "\n";
	return 0;
}
