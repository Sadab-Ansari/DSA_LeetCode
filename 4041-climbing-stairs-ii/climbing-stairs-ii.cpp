class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = LLONG_MAX / 4;
        // a = dp[j-3], b = dp[j-2], c = dp[j-1]
        long long a = INF, b = INF, c = 0;   // dp[0] = 0
        for (int j = 1; j <= n; ++j) {
            long long cur = costs[j - 1] + min({c + 1, b + 4, a + 9});
            a = b; b = c; c = cur;
        }
        return (int)c;
    }
};