class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        stack<int> inc_heights_index;
        
        for(int i = 0; i < heights.size(); ++i){
            while(!inc_heights_index.empty() && heights[i] < heights[inc_heights_index.top()]){
                int cur_height = heights[inc_heights_index.top()];
                inc_heights_index.pop();
                int left_bound = inc_heights_index.empty()?-1:inc_heights_index.top();
                
                result = max(cur_height*(i-left_bound-1), result);
            }
            inc_heights_index.push(i);
        }
        
        heights.pop_back();
        return result;
    }
};
