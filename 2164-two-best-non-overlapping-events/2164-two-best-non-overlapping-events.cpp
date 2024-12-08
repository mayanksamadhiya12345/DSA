class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        sort(ev.begin(), ev.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0;
        int maxVal = 0;
        for(auto&it : ev)
        {
            int st=it[0], en=it[1], val=it[2];

            // checking for best prev event
            while(!pq.empty() && pq.top().first < st)
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // best prev ev + curr ev
            ans = max(ans, maxVal + val);
            pq.push({en, val});
        }
        return ans;
    }
};