class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        int n=matches.size();
        map<int,int> mpp;
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            mpp[matches[i][1]]++;                    // lost match frequency;
            
            mx = max(mx,max(matches[i][0],matches[i][1]));
        }
        
        vector<bool> played(mx+1);
        for(int i=0;i<n;i++)
        {
            played[matches[i][0]] = true;
            played[matches[i][1]] = true;
        }
        
        vector<int> win;
        vector<int> los_1;
        for(int i=1;i<=mx;i++)
        {
            if(played[i] != false)
            {
                if(mpp[i]==0)
                    win.push_back(i);
                else if(mpp[i]==1)
                    los_1.push_back(i);
            }
            
        }
        
        return {win,los_1};
    }
};