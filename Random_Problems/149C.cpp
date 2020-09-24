/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* Do some math and get the relation:
* (SUM-maxElem)/2<=sumOfN/2Elements<=(SUM)/2
* And the N/2 elements above are basically
* one of the two teams (smaller one to be exact)
* Rest is pretty easy, use two pointer or prefixSums
* to get the eligible window of n/2 size.

* PS: Idk why this "sliding windows" worked at that time. I have no
* mathematical proof for the same.
* Although I proved the relation, (SUM-maxElem)/2<=sumOfN/2Elements<=(SUM)/2
* and it is correct. So I present a solution using it, below.
*/

/*
* A better choice with a proof:
* Say n is even: The sum of nums at odd indices will be more(0 based)
* The sum of elements at even indices therefore will be less than SUM/2
* Now if we remove the last element. n will get odd and SUM will become
* SUM-amax. So now when the n is odd the sum of elements at even indices
* will be more. ie it'll be more than (SUM-amax)/2. Which satiesfies our
* inequality.

* Similar proof when n is odd.

* So one group has elements at odd indices and one elements at even.
*/

void solve() {
	ll n; cin >> n;
	vll a(n, 0);

	rep(i, n) cin >> a[i];
	vector<pll> b(n);
	rep(i, n) b[i] = {a[i], i};
	sort(all(b));

	sort(all(a));

	ll l = 0, r = 1;
	vll pre(n, 0);
	rep(i, n) {
		pre[i] = a[i];
		if (i) pre[i] += pre[i - 1];
	}

	ll sum = pre.back();
	ld maxi = (sum - a.back()) / 2.0;
	ld mini = sum / 2.0;

	vll ans1, ans2;
	ll cnt = n / 2;
	fr(i, cnt - 1, n - 1) {
		ll sumInRange = pre[i];
		if (i - cnt >= 0) sumInRange -= pre[i - cnt];
		if (sumInRange <= mini && sumInRange >= maxi) {
			//i-cnt+1 ---> i
			rep(j, n) {
				if (j <= i - cnt || j > i) {
					ans2.push_back(b[j].s);
				} else {
					ans1.push_back(b[j].s);
				}
			}

			break;
		}
	}


	cout << ans1.size() << '\n';
	rep(i, ans1.size()) {
		cout << ans1[i] + 1 << ' ';
	}

	cout <<  '\n';
	cout << ans2.size() << '\n';
	rep(i, ans2.size()) {
		cout << ans2[i] + 1 << ' ';
	}
	cout << '\n';
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