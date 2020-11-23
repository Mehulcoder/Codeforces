
// Sample code to perform I/O:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll int

ll getSum(ll BITree[], ll index) {
	ll ans = 0;
	index += 1;


	while (index > 0) {
		ans += BITree[index];
		index -= index & (-index);
	}

	return ans;
}

void updateBIT(ll BITree[], ll n, ll index, ll val) {
	index++;
	while (index <= n) {
		BITree[index] += val;
		index += index & (-index);
	}

	return;
}

ll* constructBITree(ll n) {
	ll* BITree = new ll[n + 1];

	for (int i = 0; i <= n ; i++) {
		BITree[i] = 0;
	}

	return BITree;
}

ll sum(ll x, ll BITree1[], ll BITree2[]) {
	return getSum(BITree1, x) * x - getSum(BITree2, x);
}

ll getLowerBound(ll BITree1[], ll BITree2[], ll n, ll k) {
	ll lb = -1;
	ll l = 0, r = n - 1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (sum(mid, BITree1, BITree2) >= k) {
			r = mid - 1;
			lb = mid;
		} else {
			l = mid + 1;
		}
	}
	if (lb == -1) return n;
	return lb;
}

void updateRange(int BITree1[], int BITree2[], int n, int val, int l, int r) {
	updateBIT(BITree1, n, l, val);
	updateBIT(BITree1, n, r + 1, -val);

	updateBIT(BITree2, n, l, val * (l - 1));
	updateBIT(BITree2, n, r + 1, -val * r);

	return;
}

void solve() {
	ll n, q; cin >> n >> q;
	ll *BITree1 = constructBITree(n);
	ll *BITree2 = constructBITree(n);

	while (q--) {
		ll type; cin >> type;
		if (type == 0) {
			int l, r, val1;
			cin >> l >> r >> val1;
			l--; r--;
			updateRange(BITree1, BITree2, n, val1, l, r);
		} else {
			ll val2;
			cout << getLowerBound(BITree1, BITree2, n, val2) << endl;
		}
	}

	return;
}



int main() {
	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
