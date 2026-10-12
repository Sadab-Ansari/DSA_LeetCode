
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Count set bits at each bit position
        vector<int> bits(31, 0);

        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1 << b)) {
                    bits[b]++;
                }
            }
        }

        long long ans = 0;

        // Construct the largest possible values greedily
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 30; b >= 0; b--) {
                if (bits[b] > 0) {
                    x |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
