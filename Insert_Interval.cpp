/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> result;
        
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        
        vector<int> left = find_place(intervals, newInterval.start, 0, intervals.size()-1);
        vector<int> right = find_place(intervals, newInterval.end, 0, intervals.size()-1);
        
        for(int i = 0; i < left[0]; ++i){
            result.push_back(intervals[i]);
        }
        
        Interval interval;
            
        if(left[0] < left[1]){
            
            if(left[0] >= 0){
                result.push_back(intervals[left[0]]);
            }

            interval.start = newInterval.start;
            interval.end = right[0] < right[1]?newInterval.end:intervals[right[0]].end;
        }
        else{
            interval.start = intervals[left[0]].start;
            interval.end = right[0] < right[1]?newInterval.end:intervals[right[0]].end;
        }
        
        result.push_back(interval);
        for(int i = right[0] + 1; i < intervals.size(); ++i){
            result.push_back(intervals[i]);
        }
        
        return result;
    }
    
    vector<int> find_place(vector<Interval>& intervals, int value, int start, int end){
        
        vector<int> result;
        int mid = start + ((end-start)>>1);
        
        while(start <= end){
            
            if(value >= intervals[mid].start && value <= intervals[mid].end){
                result.push_back(mid);
                result.push_back(mid);
                return result;
            }
            
            else if(value < intervals[mid].start){
                end = mid - 1;
            }
            
            else{
                start = mid + 1;
            }
            
            mid = start + ((end-start)>>1);
        }
        result.push_back(end);
        result.push_back(start);
        return result;
    }
};
