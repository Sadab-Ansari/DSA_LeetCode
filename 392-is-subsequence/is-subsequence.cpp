class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; // matched character in s
            }
            j++; // always move through t
        }

        return i == s.size();
    }
};