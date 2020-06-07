/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n = intervals.size();
    if(n == 0) {
        return vector<Interval>(1, newInterval);
    }
    int i = 0;
    for(; i < n && newInterval.start > intervals[i].end; i++);
    if(i == n) {
        intervals.push_back(newInterval);
        return intervals;
    }
    int j = i;
    for( ;j < n && intervals[j].start <= newInterval.end; j++);
    j--;
    int newS = min(intervals[i].start, newInterval.start);
    int newE = max(intervals[j].end, newInterval.end);
    vector<Interval> ans;
    // cout << i << " " << j << "\n";
    // cout << intervals[j].start << " " << j << "\n";
    for(int k = 0; k < i; k++) {
        ans.push_back(intervals[k]);
    }
    ans.push_back(Interval(newS, newE));
    for(int k = j+1; k < n; k++) {
        ans.push_back(intervals[k]);
    }
    return ans;
}
