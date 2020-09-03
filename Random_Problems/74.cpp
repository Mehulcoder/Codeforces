class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size()) return 0;
		int n  = matrix.size(), m = matrix[0].size();
		int lo = 0, hi = m * n - 1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int f = mid / m, s = mid % m;
			int val = matrix[f][s];
			if (val == target) return 1;
			if (val < target)lo = mid + 1;
			else hi = mid - 1;
		}

		return 0;
	}
};