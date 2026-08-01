class Solution {
public:
    bool isPerfectSquare(int num) {

        long long left = 1;
        long long right = num;

        while (left <= right) {

            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;      // Perfect square found
            }
            else if (square < num) {
                left = mid + 1;   // Search right half
            }
            else {
                right = mid - 1;  // Search left half
            }
        }

        return false;             // No integer square equals num
    }
};