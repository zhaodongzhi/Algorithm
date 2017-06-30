class Solution {
private:
    inline void to_next(vector<int>& nums, int start)
    {
        for(int i=nums.size()-1; i>start; --i)
        {
            if(nums[start] < nums[i])
            {
                swap(nums[start], nums[i]);
                break;
            }
        }
        sort(nums.begin()+start+1, nums.end());
    }
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; --i)
        {
            if(nums[i] < nums[i+1])
            {
                to_next(nums, i);
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
