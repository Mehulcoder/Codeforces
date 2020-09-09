class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n;
	int sum = 0;
	bool get(vector<int> &nums, int start, vector<int> &sides) {
		if (start >= n) {
			return (sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0);
		}

		bool ans = 1;
		for (int i = 0; i < 4; ++i) {
			if (nums[start] > sides[i]) continue;
			int j = i;
			while (--j >= 0)
				if (sides[i] == sides[j])
					break;
			if (j != -1) continue;
			sides[i] -= nums[start];
			ans = get(nums, start + 1, sides);
			sides[i] += nums[start];
			if (ans == 1) return 1;

		}
		return 0;
	}

	bool makesquare(vector<int>& nums) {
		n = nums.size();
		if (n < 4) return 0;
		sort(nums.begin(), nums.end(), greater<int>());
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
		}
		if (sum % 4 != 0) return 0;
		else sum /= 4;
		vector<int> sides(4, sum);
		return get(nums, 0, sides);
	}
};

