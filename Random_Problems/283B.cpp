/*
Author: Mehul Chaturvedi
Talent is overrated
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fil(ar, val) memset(ar, val, sizeof(ar))

const ll N = 2e5 + 10;

ll a[N], n;
ll dp[N][2];

// X is initially 1+i
// X:1+i-a[i+1]+a[1+i-a[i+1]]....
// Y:0+i+a[i+1]+a[1+i-a[i+1]]....
//       |-----------------------> Recursion

// This function outputs the value of y-i
ll get(ll x, ll sign) {
	if (x > n || x <= 0) return 0;

	ll &ans = dp[x][(sign + 1) / 2];
	if (ans != -1) return ans;

	//This initialization to -1e13 marks that the state has been visited before
	//but the value has not been calculated yet. So we mark it with a large -ve value
	//In case DP encounters this state again. It will return this large -ve value
	//making the final ans very -ve, for which our ternary oprator checks below and
	//ouputs -1. As y can never be -ve.
	ans = -1e13;
	return ans = a[x] + get(sign * a[x] + x, sign * -1);
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	fil(dp, -1);
	cin >> n;

	//No need to worry about a[1] as it is used only
	//once that is in the initial state of x==1
	rep(i, n) cin >> a[i + 2];

	fr(i, 1, n - 1) {
		ll ans = i + get(1 + i, -1);
		cout << (ans < 0 ? -1 : ans) << '\n';
	}

	return 0 ;
}