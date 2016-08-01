class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid, result;
        while(1){
            mid = start + ((end-start)>>1);
            if(mid == start){
                result = nums[mid] < nums[end]?nums[mid]:nums[end];
                break;
            }
            if(nums[mid] < nums[end]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
};
