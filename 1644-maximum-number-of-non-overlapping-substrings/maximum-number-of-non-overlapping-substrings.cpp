class Solution {
    int extend(const string& s, int i, vector<int>& L, vector<int>& R) {
        int r = R[s[i] - 'a'];
        for (int j = i; j <= r; j++) {
            int c = s[j] - 'a';
            if (L[c] < i) return -1;      // char appears before start → invalid
            r = max(r, R[c]);
        }
        return r;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> L(26, n), R(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            L[c] = min(L[c], i);
            R[c] = i;
        }

        vector<string> res;
        int prevRight = -1;
        for (int i = 0; i < n; i++) {
            if (i != L[s[i] - 'a']) continue;   // only start at first occurrences
            int r = extend(s, i, L, R);
            if (r == -1) continue;
            if (i > prevRight) res.push_back("");  // disjoint → new slot
            prevRight = r;
            res.back() = s.substr(i, r - i + 1);  // nested → replace with smaller
        }
        return res;
    }
};