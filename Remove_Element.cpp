class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.empty()){
            return 0;
        }
        
        int lens = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                if(lens == i){
                    ++lens;
                    continue;
                }
                nums[lens++] = nums[i];
            }
        }
        
        return lens;
    }
};
