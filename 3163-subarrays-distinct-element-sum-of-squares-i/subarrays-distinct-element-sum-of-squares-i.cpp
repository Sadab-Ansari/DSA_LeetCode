class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Choose the starting point
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            // Extend the subarray
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                int distinct = st.size();

                // Add square of distinct count
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};