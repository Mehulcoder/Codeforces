class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long;
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		ll n = nums.size();
		multiset<ll> s;

		if (k == 0) return 0;
		for (ll i = 1; i < k && i < n; ++i) {
			s.insert(nums[i]);
		}

		for (ll i = 0; i < n; ++i) {
			ll curr = (ll)nums[i];
			ll leftToRemove = i - k - 1;
			ll rightToAdd = i + k;
			if (leftToRemove >= 0) {
				ll toRemove = nums[leftToRemove];
				s.erase(s.find(toRemove));
			}

			if (rightToAdd < n) {
				ll toAdd = nums[rightToAdd];
				s.insert(toAdd);
			}

			//Find the just greater element or equal
			auto it = s.lower_bound(curr);
			if (it != s.end()) {
				if (abs((*it) - curr) <= (ll)t) return 1;
			}

			//Find the just lower element
			if (it != s.begin()) {
				it--;
				if (abs((*it) - curr) <= (ll)t) {
					return 1;
				}
			}

			s.insert(curr);
			if (i + 1 < n) {
				s.erase(s.find(nums[i + 1]));
			}
		}

		return 0;

	}
};
