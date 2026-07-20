class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        // store all the elements in a temp vector
        vector<int> temp;
        for(auto i : grid)
        {
            for(auto j : i)
            {
                temp.push_back(j);
            }
        }
        
        int n = temp.size();
        k = k % n;
        
        // for storing in the correct sequence
        vector<int> res; 
        
        // last k vales at the start
        for(int i= n-k; i<n; i++)
        {
            res.push_back(temp[i]);
        }
        
        // starting values at the end
        for(int i=0; i<n-k; i++){
             res.push_back(temp[i]);
        }
        
        int m = grid[0].size();
        temp.clear();
        grid.clear();
        
        for(int i=0;i<res.size();i++)
        {
            if(temp.size() < m)
                temp.push_back(res[i]);
            
            if(temp.size()==m)
            {
                grid.push_back(temp);
                temp.clear();
            }
        }
        return grid;
    }
};