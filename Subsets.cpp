class Solution {
private:
    void help(int start, vector<int>& nums, vector<int>& element, vector<vector<int>>& result){
        result.push_back(element);
        for(int i = start; i < nums.size(); ++i){
            element.push_back(nums[i]);
            help(i+1, nums, element, result);
            element.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> element;
        help(0, nums, element, result);
        return result;
    }
};
