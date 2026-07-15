class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // two pointer
        int write=0;
        for (int i =0; i<nums.size(); i++){
            if (nums[i]!=0){
                nums[write]=nums[i];
                write++;
            }
        }
        while(write<nums.size()){
            nums[write]=0;
            write++;
        }
    }
};