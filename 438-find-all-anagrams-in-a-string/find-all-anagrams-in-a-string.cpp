class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        // If p is longer than s, impossible
        if (p.size() > s.size())
            return ans;

        // Frequency arrays
        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // Count characters of p
        for (char c : p)
            pFreq[c - 'a']++;

        // Count first window
        for (int i = 0; i < p.size(); i++)
            windowFreq[s[i] - 'a']++;

        // Check first window
        if (windowFreq == pFreq)
            ans.push_back(0);

        // Slide the window
        for (int i = p.size(); i < s.size(); i++) {

            // Remove left character
            windowFreq[s[i - p.size()] - 'a']--;

            // Add new right character
            windowFreq[s[i] - 'a']++;

            // If frequencies match, save index
            if (windowFreq == pFreq)
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};