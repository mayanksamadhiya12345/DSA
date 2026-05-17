class Solution {
public:
    bool solve(vector<int>& arr, int n, int start, vector<bool>& vis) {
        if(start<0 || start>=n || vis[start])
            return false;

        vis[start] = true;
        if(arr[start]==0) return true;

        return solve(arr, n, start-arr[start], vis) || solve(arr, n, start+arr[start], vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n, false);
        return solve(arr, n, start, vis);
    }
};