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

// METHOD - 1 - SORTING

bool cmp(Interval& a, Interval& b){ 
    return a.start < b.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if(n == 0 || n == 1)
            return true;
        
        sort(intervals.begin(), intervals.end(), cmp); // sorting based on start times
        
        for(int i = 0; i < n - 1; i++){
            if(intervals[i].end > intervals[i + 1].start)
                return false;
        }

        return true;
    }
};
