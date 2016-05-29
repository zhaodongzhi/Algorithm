class Solution {
public:
    int climbStairs(int n) {
        if(n < 0){
            return 0;
        }
        int n1 = 1, n2 = 1;
        for(int i = 2; i <= n; ++i){
            n2 = n1 + n2;
            n1 = n2 - n1;
        }
        return n2;
    }
};
