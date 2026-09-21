class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);   // subarrays ending at previous index

        for (int num : nums) {
            int v = num % k;
            vector<long long> next(k, 0);
            next[v] += 1;                          // new subarray [i..i]
            for (int r = 0; r < k; r++) {
                if (cnt[r]) next[(r * v) % k] += cnt[r];   // extend old ones
            }
            for (int r = 0; r < k; r++) result[r] += next[r];
            cnt = next;
        }
        return result;
    }
};