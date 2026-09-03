class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());
        if (mn % 2 != 0) return true;      // min is odd -> always possible
        for (int x : nums1)                // min is even -> need all even
            if (x % 2 != 0) return false;
        return true;
    }
};