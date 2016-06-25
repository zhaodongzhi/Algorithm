class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()){
            return result;
        }
        sort(nums.begin(), nums.end());
        int nums_len = nums.size();
        for(int left = 0; left < nums_len - 2; ++left){
            int sum = -nums[left];
            for(int mid = left+1, right = nums.size()-1; mid < right;){
                if(nums[mid] + nums[right] == sum){
                    vector<int> temp = {nums[left], nums[mid], nums[right]};
                    result.push_back(temp);
                    while(nums[mid] == nums[mid+1]) ++mid;
                    while(nums[right] == nums[right-1]) --right;
                    ++mid;
                    --right;
                }
                else if(nums[mid] + nums[right] < sum) ++mid;
                else --right;
            }
            while(left < nums_len-2 && nums[left] == nums[left+1]){
                ++left;
            }
        }
        return result;
    }
};
