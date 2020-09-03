
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}


	using ll = long long;
	ll INF = 4557430888798830399ll;

	int maxSubarraySumCircular(vector<int>& A) {
		ll maxTillNow = -INF, n = A.size();
		ll maxEndingHere = -INF;
		ll start = 0;
		while (start < A.size()) {
			maxEndingHere = max(maxEndingHere + A[start], (ll)A[start]);
			maxTillNow = max(maxTillNow, maxEndingHere);
			start++;
		}

		//Prefix + suffix
		vector<ll> prefix(n, 0), suffix(n, 0), maxSuffTill(n, 0);
		for (ll i = 0; i < n; ++i) {
			prefix[i] = A[i];
			if (i != 0) prefix[i] += prefix[i - 1];
		}

		for (ll i = n - 1; i >= 0; --i) {
			suffix[i] = A[i];
			maxSuffTill[i] = max(A[i], 0);
			if (i != n - 1) {
				suffix[i] += suffix[i + 1];
				maxSuffTill[i] = max(suffix[i], maxSuffTill[i + 1]);
			}
		}

		for (ll i = 0; i < n; ++i) {
			ll sum = prefix[i];
			if (i != n - 1) sum += maxSuffTill[i + 1];
			maxTillNow = max(maxTillNow, sum);
		}

		return maxTillNow;
	}
};