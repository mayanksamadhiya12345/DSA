class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto&it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> inDegree(numCourses);
        for(int i=0;i<numCourses;i++) {
            for(auto&it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(inDegree[i]==0) {
                q.push(i);
            }
        }

        int ans = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans++;

            for(auto&it:adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(numCourses == ans) return true;
        return false;
    }
};