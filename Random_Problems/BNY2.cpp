// C++ Program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;
#define M 1000
#define int long long int

// Function to count the N digit numbers
// whose sum is divisible by K
int countNum(int N, int sum, int K,
             bool st, int dp[M][M][2]) {
    // Base case
    if (N == 0 and sum == 0) {
        return 1;
    }
    if (N < 0) {
        return 0;
    }

    // If already computed
    // subproblem occurred
    if (dp[N][sum][st] != -1) {
        return dp[N][sum][st];
    }

    // Store the count of N digit numbers
    // whoe sum is divisible by K
    int res = 0;

    // Check if the number does not contan
    // any leading 0.
    int start = st == 1 ? 0 : 1;

    // Recurrence relation
    for (int i = start; i <= 9; i++) {
        res += countNum(N - 1, (sum + i) % K,
                        K, (st | i > 0), dp);
    }

    return dp[N][sum][st] = res;
}

// Driver Code
int main() {
    int N = 2, K = 7;

    // Stores the values of
    // overlapping subproblems
    int dp[M][M][2];

    memset(dp, -1, sizeof(dp));

    cout << countNum(N, 0, K, 0, dp);
}