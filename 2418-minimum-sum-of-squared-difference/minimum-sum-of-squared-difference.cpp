class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> d(n);
        for (int i = 0; i < n; i++) d[i] = abs(nums1[i] - nums2[i]);

        long long k = (long long)k1 + k2;
        sort(d.rbegin(), d.rend());
        d.push_back(0);                 // sentinel: we never need to go below 0

        long long cur = d[0];
        for (int i = 0; i < n; i++) {
            long long w = i + 1, nxt = d[i + 1];
            long long cost = (cur - nxt) * w;   // lower top w values to nxt
            if (cost <= k) {
                k -= cost;
                cur = nxt;
                continue;
            }
            // Can't reach nxt: spread remaining k over the top w values
            cur -= k / w;
            long long rem = k % w;
            long long ans = rem * (cur - 1) * (cur - 1) + (w - rem) * cur * cur;
            for (int j = i + 1; j < n; j++) ans += d[j] * d[j];
            return ans;
        }
        return 0;   // budget covered every difference
    }
};