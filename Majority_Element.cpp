class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int count = 1;
        int i = 0;
        for(int j = 1; j < nums.size(); ++j){
            if(nums[j] == nums[i]){
                ++count;
            }
            else{
                --count;
                if(count == 0){
                    i = j;
                    count = 1;
                }
            }
        }
        return nums[i];
    }
};
