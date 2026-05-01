/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool cmp(Interval& a, Interval& b){
    
    return a.start < b.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if(n == 0 || n == 1)
            return true;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int last = intervals[0].end;
        
        for(int i = 1; i < n; i++){
            if(intervals[i].start < last)
                return false;
            
            last = intervals[i].end;
        }

        return true;
    }
};
