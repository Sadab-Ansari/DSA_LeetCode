class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // prefMax[i] = maximum element in nums[0 ... i-1]
        vector<int> prefMax(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // suffMin[i] = minimum element in nums[i ... n-1]
        vector<int> suffMin(n + 1, 1000000000);

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // prefDrop[i] = number of adjacent decreases
        // in nums[0 ... i]
        vector<int> prefDrop(n, 0);

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1];

            if (nums[i - 1] > nums[i]) {
                prefDrop[i]++;
            }
        }

        // Check whether a particular k is sortable
        auto check = [&](int k) -> bool {

            for (int start = 0; start < n; start += k) {

                int end = start + k - 1;

                // Count decreases inside this block
                int drops = prefDrop[end] - prefDrop[start];

                // Because the block is circular, also check
                // the connection from last element back to first.
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // A circular array can be rotated into sorted order
                // only if it has at most one circular decrease.
                if (drops > 1) {
                    return false;
                }

                // Everything before this block must be <=
                // everything from this block onward.
                if (prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int answer = 0;

        // Only divisors of n can be valid k.
        for (int k = 1; k <= n / k; k++) {

            if (n % k == 0) {

                // k is a divisor
                if (check(k)) {
                    answer += k;
                }

                // n/k is the paired divisor
                int other = n / k;

                if (other != k && check(other)) {
                    answer += other;
                }
            }
        }

        return answer;
    }
};