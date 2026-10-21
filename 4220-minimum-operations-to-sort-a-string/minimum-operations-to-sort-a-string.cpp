
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        string t = s;
        sort(t.begin(), t.end());

        // Check if one operation is enough
        string temp = s;
        sort(temp.begin(), temp.end() - 1);

        if (temp == t)
            return 1;

        temp = s;
        sort(temp.begin() + 1, temp.end());

        if (temp == t)
            return 1;

        // Three operations are required only when
        // the first character is the unique maximum
        // and the last character is the unique minimum.
        char mx = *max_element(s.begin(), s.end());
        char mn = *min_element(s.begin(), s.end());

        int maxCount = count(s.begin(), s.end(), mx);
        int minCount = count(s.begin(), s.end(), mn);

        if (s[0] == mx && s[n - 1] == mn &&
            maxCount == 1 && minCount == 1) {
            return 3;
        }

        return 2;
    }
};
