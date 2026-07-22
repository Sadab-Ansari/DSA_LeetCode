class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // Step 1: Calculate sum of first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // First window is the current maximum
        int maxSum = sum;

        // Step 2: Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Remove leftmost element
            sum -= nums[i - k];

            // Add new rightmost element
            sum += nums[i];

            // Update maximum sum
            maxSum = max(maxSum, sum);
        }

        // Return maximum average
        return (double)maxSum / k;
    }
};