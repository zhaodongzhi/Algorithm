class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int result = 0x80000001;
        int tempresult = 0;
        int maxelement = 0x80000001;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > maxelement){
                maxelement = nums[i];
            }
            if(tempresult < 0){
                tempresult = 0;
            }
            tempresult += nums[i];
            if(tempresult > result){
                result = tempresult;
            }
        }
        if(maxelement < 0){
            return maxelement;
        }
        return result;
    }
};
