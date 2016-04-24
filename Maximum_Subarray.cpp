class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int result = 0x80000001;
        int tempresult = 0;
        for(int i = 0; i < nums.size(); ++i){
            tempresult += nums[i];
            if(tempresult > result){
                result = tempresult;
            }
            if(tempresult < 0){
                tempresult = 0;
            }
        }
        return result;
    }
};
