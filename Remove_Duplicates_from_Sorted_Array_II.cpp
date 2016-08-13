class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int target = nums[0];
        int times = 1;
        int lens = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == target){
                if(times == 1){
                    nums[lens] = nums[i];
                    ++lens;
                }
                times = 2;
            }
            else{
                nums[lens] = nums[i];
                target = nums[i];
                times = 1;
                ++lens;
            }
        }
        return lens;
    }
};
