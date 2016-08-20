/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval& left, const Interval& right){
    return left.start < right.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), compare);
        Interval temp(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); ++i){
            if(temp.end >= intervals[i].start){
                temp.end = max(temp.end, intervals[i].end);
            }
            else{
                result.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        result.push_back(temp);
        return result;
    }
};
