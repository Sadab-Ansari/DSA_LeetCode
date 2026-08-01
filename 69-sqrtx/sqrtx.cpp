class Solution {
public:
    int mySqrt(int x) {

        int left = 1;
        int right = x;
        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            }

            else if (square < x) {
                ans = mid;          // Best answer so far
                left = mid + 1;     // Try larger number
            }

            else {
                right = mid - 1;    // Too large
            }
        }

        return ans;
    }
};