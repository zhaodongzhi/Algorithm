class Solution {
private:
    void help(int start, vector<int>& nums, vector<int>& sub_set, vector<vector<int>>& result){
        result.push_back(sub_set);
        for(int i = start; i < nums.size(); ++i){
            sub_set.push_back(nums[i]);
            help(i+1, nums, sub_set, result);
            sub_set.pop_back();
            while(i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> sub_set;
        help(0, nums, sub_set, result);
        return result;
    }
};
