class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        int result = 0;
        int _min = 0x7fffffff;
        
        int _max = nums[nums_size-1]+nums[nums_size-2]+nums[nums_size-3];
        if(_max < target) return _max;
        
        for(int i = 0; i+2 < nums_size; ++i){
            
            int temp1 = nums[i]+nums[i+1]+nums[i+2];
            if(temp1 > target && temp1-target >= _min) break;
            
            for(int start = i+1, end = nums_size-1; start < end;){
                int _sum = nums[i]+nums[start]+nums[end];
                int _abs = abs(target-_sum);
                
                if(_abs == 0) return _sum;
                
                if(_abs < _min){
                    _min = _abs;
                    result = _sum;
                }
                if(_sum > target) --end;
                else ++start;
            }
        }
        return result;
    }
};
