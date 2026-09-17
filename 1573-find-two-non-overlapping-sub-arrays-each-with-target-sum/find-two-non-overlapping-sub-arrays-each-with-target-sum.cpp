class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX / 2;
        vector<int> best(n, INF);
        int ans = INF, sum = 0, l = 0;

        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target) sum -= arr[l++];

            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && best[l - 1] < INF)
                    ans = min(ans, best[l - 1] + len);
                best[r] = len;
            }
            if (r > 0) best[r] = min(best[r], best[r - 1]);
        }
        return ans >= INF ? -1 : ans;
    }
};