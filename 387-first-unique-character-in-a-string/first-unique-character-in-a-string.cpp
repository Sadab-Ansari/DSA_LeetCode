class Solution {
public:
    int firstUniqChar(string s) {
        // int count;
        // for (int i=0; i<s.size(); i++){
        // count=0;
        // for (int j=0; j<s.size(); j++){
        //     if(s[i]==s[j]){
        //         count++;
        //     }
        // }
        // if(count==1){
        //     return i;
        // }
        // }
        // return -1;
         int count[26] = {0};

        // Count frequency of each letter
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        // Find first letter with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};