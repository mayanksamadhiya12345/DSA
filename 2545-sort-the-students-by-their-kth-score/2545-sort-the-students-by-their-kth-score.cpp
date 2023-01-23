class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        int n = score.size();                   // rows
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({score[i][k],i});       // stroing {score of Kth col in ith row, and their ith row value}
        }
        
        sort(v.begin(),v.end(),greater<> ());                // based on decreasing score of kth col
        
        vector<vector<int>> ans;
        for(auto &it : v)
        {
            ans.push_back(score[it.second]);        // now put each row one by one into our ans in decresing manner(based on kth col)
        }
        return ans;
    }
};