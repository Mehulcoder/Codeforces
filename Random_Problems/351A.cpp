/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

const ll N = 4e3 + 5;
ld v[N], dp[N][N], sum = 0;
ll a[N], b[N], n;

/*
* dp[i][j] --> The "signed" diff till i such that "abs(dp[i][j])" is
* minimum and we have taken j floor values till now.
*/

ld get(ll end, ll floorCount = n / 2) {
	if (floorCount < 0) return INF;
	if (end < 0 && floorCount == 0) return 0;
	if (end < 0 && floorCount != 0) return INF;

	ld &ans = dp[end][floorCount];
	if (ans != -1.0) return ans;

	ld takeFloor = get(end - 1, floorCount - 1) + v[end] - a[end];
	ld takeCiel = get(end - 1, floorCount) + v[end] - b[end];

	if (abs(takeFloor) <= abs(takeCiel)) {
		return ans = takeFloor;
	}
	return ans = takeCiel;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n;
	n = 2 * n;

	rep(i, N) rep(j, N) dp[i][j] = -1.0;
	rep(i, n) {
		cin >> v[i];
		sum += v[i];
		a[i] = floor(v[i]);
		b[i] = ((a[i] * 1.0) < v[i] ? (a[i] + 1) : (a[i]));
	}

	get(n - 1);

	cout << fixed << setprecision(3) << abs(dp[n - 1][n / 2]) << '\n';

	return 0 ;
}