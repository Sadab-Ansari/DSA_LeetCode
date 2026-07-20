class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for(char ch:jewels){
            s.insert(ch);
        } 
        int count=0;
        for (char ch:stones){
            if(s.count(ch)){
                count++;
            }
        }
        return count;

    }
};