class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        long long med = nums[n / 2], moves = 0;
        for (int x : nums) moves += llabs(x - med);
        return (int)moves;
    }
};