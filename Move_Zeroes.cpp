class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, zero_index = 0;
        for(i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                nums[zero_index++] = nums[i];
            }
        }
        while(zero_index < nums.size()){
            nums[zero_index++] = 0;
        }
    }
};
