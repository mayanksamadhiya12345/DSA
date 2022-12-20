class Solution 
{
public:
    void dfs(int room,vector<bool>& vis,vector<vector<int>>& rooms)
    {
        vis[room] = true;
        for(auto it : rooms[room])
        {
            if(!vis[it])
            {
                dfs(it,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> vis(n,false);
        
        // dfs traversal
        dfs(0,vis,rooms);               // starts from 0 because it is unlocked room
        
        for(auto it : vis)
        {
            if(!it) return false;
        }
        return true;
    }
};