class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size(), best = -1, sum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target && l <= r) sum -= nums[l++];
            if (sum == target) best = max(best, r - l + 1);
        }
        return best == -1 ? -1 : n - best;
    }
};