class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // divisors d of L with d < L
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; d++)
            for (int L = 2 * d; L <= n; L += d)
                divs[L].push_back(d);

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                for (int d : divs[L]) {
                    int m = L / d, cnt = 0;
                    for (int r = 0; r < d; r++)
                        for (int t = 0; t < m / 2; t++)
                            if (s[i + r + t * d] != s[i + r + (m - 1 - t) * d])
                                cnt++;
                    cost[i][j] = min(cost[i][j], cnt);
                }
            }
        }

        // dp[j][p] = min changes for first j chars split into p parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++)
            for (int j = 2; j <= n; j++)
                for (int i = 0; i + 2 <= j; i++)
                    if (dp[i][p - 1] < INF)
                        dp[j][p] = min(dp[j][p], dp[i][p - 1] + cost[i][j - 1]);

        return dp[n][k];
    }
};