class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // brute force 
        // Time Complexity: O(n log n)
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;

    }
};