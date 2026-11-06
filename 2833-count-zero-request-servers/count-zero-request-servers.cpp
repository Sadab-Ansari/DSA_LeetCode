class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0);
        vector<int> ans(m);
        int active = 0;          // servers with >=1 request in window
        int left = 0, right = 0; // window over logs
        int L = logs.size();

        for (int qi : idx) {
            int q = queries[qi];

            // expand: add logs with time <= q
            while (right < L && logs[right][1] <= q) {
                if (cnt[logs[right][0]]++ == 0) active++;
                right++;
            }
            // shrink: remove logs with time < q - x
            while (left < right && logs[left][1] < q - x) {
                if (--cnt[logs[left][0]] == 0) active--;
                left++;
            }

            ans[qi] = n - active;
        }
        return ans;
    }
};