class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        int k = 1;
        for(int s = 0;k <= n*n && s <= n/2; ++s){
            int i = s;
            int j = s;
            while(j < n-s-1) result[i][j++] = k++;
            while(i < n-s-1) result[i++][j] = k++;
            while(j > s) result[i][j--] = k++;
            while(i > s) result[i--][j] = k++;
        }
        if(k <= n*n) result[n/2][n/2] = n*n;
        return result;
    }
};
