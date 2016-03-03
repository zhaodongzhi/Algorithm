class Solution {
public:
    inline bool BinarySearch(vector<int>& array, int target, int begin, int end){
        if(target < array[begin] | target > array[end]){
            return false;
        }
        while(begin != end){
            if(begin == end - 1){
                return array[begin] == target | array[end] == target;
            }
            int mid = begin + (end - begin)/2;
            if(array[mid] == target){
                return true;
            }
            else if(target < array[mid]){
                end = mid - 1;
            }
            else if(target > array[mid]){
                begin = mid + 1;
            }
        }
        return array[begin] == target;
    }
    inline bool BinarySearch_2D(vector<vector<int>>& matrix, int target, int row_begin, int row_end){
        int row_size = matrix[0].size();
        
        while(row_begin != row_end){
            if(row_begin == row_end - 1){
                return BinarySearch(matrix[row_begin], target, 0, row_size-1) | BinarySearch(matrix[row_end], target, 0, row_size-1) ;
            }
            int row_mid = row_begin + (row_end - row_begin)/2;
            if(target < matrix[row_mid][0]){
                return BinarySearch_2D(matrix, target, row_begin, row_mid - 1);
            }
            if(target > matrix[row_mid][row_size-1]){
                return BinarySearch_2D(matrix, target, row_mid + 1, row_end);
            }
            if(BinarySearch(matrix[row_mid], target, 0, row_size-1) == true){
                return true;
            }
            return BinarySearch_2D(matrix, target, row_begin, row_mid - 1) | BinarySearch_2D(matrix, target, row_mid + 1, row_end);
        }
        return BinarySearch(matrix[row_begin], target, 0, row_size-1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        if(matrix[0].size() == 0){
            return false;
        }
        return BinarySearch_2D(matrix, target,0, matrix.size()-1);
    }
};
