class Solution {
private: 
    static bool compare(Interval &i1, Interval &i2){
        return i1.start < i2.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compare);
        std::priority_queue<int, vector<int>, std::greater<int>> endTimeOfRooms;.鐣欏璁哄潧-涓€浜�-涓夊垎鍦�
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


//--------brute force---------//

public static int max(Interval[] intervals) {
                // O(n*k) time space o(max-min)
                HashMap<Integer, Integer> map = new HashMap<>();
                for (int i = 0; i < intervals.length; i++) {
                        Interval cur = intervals[i];
                        for (int j = cur.start; j <= cur.end; j++) {
                                if (map.containsKey(j)) {
                                        map.put(j, map.get(j) + 1);
                                } else {
                                        map.put(j, 1);
                                }
                        }
                }
                int max = 1;
                for (int key : map.keySet()) {
                        max = Math.max(max, map.get(key));
                }
                for (int key : map.keySet()) {
                        if (map.get(key) == max) {
                                return key;
                        }
                }
                return 0;
        }