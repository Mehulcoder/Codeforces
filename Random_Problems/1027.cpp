class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int dp[n][1001];

        memset(dp, 0, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j] + 500;
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans + 1;
    }
};