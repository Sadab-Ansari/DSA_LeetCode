class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // If s1 is longer, impossible
        if (s1.size() > s2.size())
            return false;

        // Frequency arrays for 26 lowercase letters
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count frequency of s1
        for (char ch : s1)
            freq1[ch - 'a']++;

        // Count frequency of first window in s2
        for (int i = 0; i < s1.size(); i++)
            freq2[s2[i] - 'a']++;

        // If first window matches
        if (freq1 == freq2)
            return true;

        // Slide the window
        for (int i = s1.size(); i < s2.size(); i++) {

            // Add new character entering the window
            freq2[s2[i] - 'a']++;

            // Remove character leaving the window
            freq2[s2[i - s1.size()] - 'a']--;

            // Compare frequencies
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};