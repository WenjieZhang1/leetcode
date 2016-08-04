class Solution {
private:  
    static bool compare(Interval &i1, Interval &i2){
        return i1.start < i2.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compare);
        std::priority_queue<int, vector<int>, std::greater<int>> endTimeOfRooms;
        for(auto it : intervals){
            if(!endTimeOfRooms.empty() && endTimeOfRooms.top() <= it.start){
                endTimeOfRooms.pop();
                endTimeOfRooms.push(it.end);
            }
            else 
                endTimeOfRooms.push(it.end);
        }
        return endTimeOfRooms.top();
    }
};