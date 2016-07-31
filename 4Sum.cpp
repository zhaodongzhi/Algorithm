class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_len = nums.size();
        vector<vector<int>> result;
        if(nums_len < 4){
            return result;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums_len-3; ++i){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if(nums[i] + nums[nums_len-1] + nums[nums_len-2] + nums[nums_len-3]  < target) continue;
            
            for(int j = i+1; j < nums_len-2; ++j){
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[nums_len-1] + nums[nums_len-2]  < target) continue;
            
                int temp_target = target - nums[i] - nums[j];
                for(int start=j+1, end=nums_len-1; start < end;){
                    if(nums[start] + nums[end] < temp_target) ++start;
                    else if(nums[start] + nums[end] > temp_target) --end;
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[start], nums[end]};
                        result.push_back(temp);
                        do{++start;}while(nums[start-1] == nums[start] && start < end);
                        do{--end;} while(nums[end] == nums[end+1] && start < end);
                    }
                }
            }
        }
        return result;
    }
};
