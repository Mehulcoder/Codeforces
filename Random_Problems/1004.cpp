class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int i = 0, j = 0;
		while (i < A.size()) {
			K -= 1 - A[i++];
			if (K < 0) K += 1 - A[j++];
		}
		return i - j;
	}
};