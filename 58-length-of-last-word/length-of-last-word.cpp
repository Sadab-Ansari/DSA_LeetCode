class Solution {
public:
    int lengthOfLastWord(string s) {
       int i = s.size() -1;
       int count=0;
       while (i>=0 && isspace(s[i])) {
        i--;
       }
       while(i>=0 && !isspace(s[i])){
        count++;
        i--;
       }
       return count;
    }
};