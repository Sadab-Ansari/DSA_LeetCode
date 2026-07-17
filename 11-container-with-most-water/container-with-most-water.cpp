class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0;
        int right = h.size() - 1;
        int maxArea = 0;

        while (left < right) {

            int width = right - left;
            int h1 = min(h[left], h[right]);
            int area = width * h1;

            maxArea = max(maxArea, area);

            if (h[left] < h[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};