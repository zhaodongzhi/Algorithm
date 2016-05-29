class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0){
            return false;
        }
        int cols = matrix[0].size();
        if(cols == 0){
            return false;
        }
        for(int i = rows-1, j = 0; i>=0 && j<cols;){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                j++;
            }
            else{
                i--;
            }
        }
        return false;
    }
};
