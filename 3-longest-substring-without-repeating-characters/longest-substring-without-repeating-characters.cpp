// 1.sliding window 2.hash map 3.two pointer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;   // Stores characters in current window

        int left = 0;             // Left pointer
        int maxLen = 0;           // Stores answer

        // Expand window
        for (int right = 0; right < s.size(); right++) {

            // If duplicate exists, shrink window
            while (st.count(s[right])) {

                st.erase(s[left]);   // Remove left character
                left++;              // Move left forward
            }

            // Insert current character
            st.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};