class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> s;
        vector<int> ans;
        for(int num:num1){
            s.insert(num);
        }
        for(int num:num2){
            if(s.count(num)){
                ans.push_back(num);
                s.erase(num);
            }
        }
        return ans;
    }
};