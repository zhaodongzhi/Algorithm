class Solution {
public:
    int mySqrt(int x) {
        double xn = 0x5f3759df;
        double result = (xn + (double)x/xn)*0.5;
        while (abs(int(result) - int(xn)) > 0){
            xn = result;
            result = (xn + (double)x/xn)*0.5;
        }
        return (int)result;
    }
};
