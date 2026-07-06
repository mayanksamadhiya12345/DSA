class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0]==b[0]) {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return 1;
        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        int maxEnd = 0;
        for (auto &it : intervals) {
            if (it[1] <= maxEnd) {
                count++;
            } else {
                maxEnd = it[1];
            }
        }
        return intervals.size() - count;
    }
};