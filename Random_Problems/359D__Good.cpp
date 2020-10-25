#include <bits/stdc++.h>
using namespace std;

int n, fin, a[300001], res[300001], cnt[300001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) {
		int l = i, r = i;
		while (l > 0 && a[l - 1] % a[i] == 0) l--;
		while (r < n - 1 && a[r + 1] % a[i] == 0) r++;
		i = r;
		res[l] = max(r, res[l]);
		cnt[r - l]++;
		fin = max(r - l, fin);
	}
	printf("%d %d\n", cnt[fin], fin);
	for (int i = 0; i < n; i++) if (res[i] - i == fin) printf("%d ", i + 1);
}