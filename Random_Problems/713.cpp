class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	/*
	* I check for every right index, the number of possible ways to make
	* subarrays ending at there with product strictly less than k.
	*/
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1) return 0;
		int n = nums.size(), prod = 1, ans = 0, left = 0;
		for (int i = 0; i < n; i++) {
			prod *= nums[i];
			while (prod >= k) prod /= nums[left++];
			ans += i - left + 1;
		}
		return ans;
	}
};
