class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(n2)
        // for (int i=0; i<nums.size(); i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         if(nums[i]==nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;

// hash table
       unordered_set<int> s;
       for (int i=0; i<nums.size(); i++){
        if(s.count(nums[i])){
        return true;
        }

       s.insert(nums[i]);
       }
       return false;



    }
};