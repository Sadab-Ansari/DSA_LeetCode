class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        // Split string into words
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {

            if (mp1.count(pattern[i]) && mp1[pattern[i]] != words[i])
                return false;

            if (mp2.count(words[i]) && mp2[words[i]] != pattern[i])
                return false;

            mp1[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
        }

        return true;
    }
};