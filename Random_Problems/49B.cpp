/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>


vector<ll> ans;
/*
* We'll use the lowest possible base greedily
* Because that always increases the carry amount.
*/
void getSum(ll a, ll b, ll base, ll carry = 0) {
	if (a == 0 && b == 0 && carry == 0) return;
	ll last = a % 10 + b % 10 + carry;
	ll lastDig = (last < base ? last : last - base);
	carry = (last < base ? 0 : 1);
	ans.push_back(lastDig);
	getSum(a / 10, b / 10, base, carry);
}

void solve() {
	ll a, b; cin >> a >> b;

	ll t1 = a, t2 = b;
	ll maxi = 0;
	while (t1) {
		maxi = max(maxi, t1 % 10);
		t1 /= 10;
	}
	while (t2) {
		maxi = max(maxi, t2 % 10);
		t2 /= 10;
	}

	maxi++;
	maxi = max(2ll, maxi);
	getSum(a, b, maxi);
	cout << ans.size() << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0 ;
}