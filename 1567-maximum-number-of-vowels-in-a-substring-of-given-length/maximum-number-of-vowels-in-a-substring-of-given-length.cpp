class Solution {
public:

    // Function to check whether a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // Step 1: Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        // Assume first window has maximum vowels
        int maxCount = count;

        // Step 2: Slide the window
        for (int i = k; i < s.length(); i++) {

            // Remove the leftmost character of previous window
            if (isVowel(s[i - k])) {
                count--;
            }

            // Add the new rightmost character
            if (isVowel(s[i])) {
                count++;
            }

            // Update maximum vowels found so far
            maxCount = max(maxCount, count);
        }

        // Return the maximum number of vowels
        return maxCount;
    }
};