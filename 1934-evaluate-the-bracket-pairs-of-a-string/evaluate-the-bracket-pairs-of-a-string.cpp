class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge) mp[k[0]] = k[1];

        string res, key;
        bool inBracket = false;
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key.clear();
            } else if (c == ')') {
                inBracket = false;
                auto it = mp.find(key);
                res += (it != mp.end()) ? it->second : "?";
            } else if (inBracket) {
                key += c;
            } else {
                res += c;
            }
        }
        return res;
    }
};