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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        int n = intervals.size();
        if(n == 0)
            return 0;
        
        vector<int> start, end;

        for(auto pair : intervals){
            start.push_back(pair.start);
            end.push_back(pair.end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int count = 1;    
        int ans = 1;        // atleast one day is needed, when no meetings overlaps
        
        int i = 0;          
        int j = 1;          
        
        while (i < n && j < n){
            
            if(start[j] < end[i]){  
                count++;
                j++;
            }
            else{
                count--;
                i++;
            }
            
            ans = max(count, ans);    
        }
        
        return ans;
    }
};