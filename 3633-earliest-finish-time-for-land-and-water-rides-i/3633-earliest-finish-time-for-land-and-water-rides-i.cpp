class Solution {
public:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(), m=waterStartTime.size();
        int mn_water=INT_MAX, mn_land=INT_MAX;

        for(int i=0;i<n;i++) {
            mn_land = min(mn_land, landStartTime[i]+landDuration[i]);
        }

        cout<<mn_land;

        for(int i=0;i<m;i++) {
            mn_water = min(mn_water, max(mn_land, waterStartTime[i]) + waterDuration[i]);
        }
        return mn_water;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int ans2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(ans1, ans2);
    }
};