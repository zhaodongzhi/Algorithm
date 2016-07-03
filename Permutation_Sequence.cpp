class Solution {
public:
    int factorial[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string getPermutation(int n, int k) {
        string result(n, '0');
        for(int i = 0; i < n; ++i){
            result[i] = '0' + i + 1;
        }
        int begin_index = 0;
        --k;
        while(--n){
            int m = begin_index + k/factorial[n];
            k = k%factorial[n];
            char c = result[m];
            for(int i = m; i > begin_index; --i){
                result[i] = result[i-1];
            }
            result[begin_index++] = c;
        }
        return result;
    }
};
