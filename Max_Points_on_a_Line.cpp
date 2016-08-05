/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    int gcd(int a, int b) {
        
        if(b==0) return a;
        return gcd(b, a%b);
    }
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3){
            return points.size();
        }
        int max_result = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map<double, int> grad_map;
            int vertical = 1;
            int result = 1;
            int same = 0;
            for(int j = i+1; j < points.size(); ++j){
                if(points[j].x-points[i].x == 0){
                    if(points[j].y-points[i].y == 0)
                        same += 1;
                    else{
                        vertical += 1;
                        result = max(result, vertical);
                    }
                    continue;
                }
                int _x = points[j].x-points[i].x;
                int _y = points[j].y-points[i].y;
                double grad = 1.0*(_y)/_x;
                grad_map[grad] += 1;
                result = max(result, grad_map[grad]+1);
            }
            max_result = max(max_result, result+same);
        }
        return max_result;
    }
};
