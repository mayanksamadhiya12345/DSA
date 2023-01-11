class Solution
{
private:
    vector<vector<int>> graph;
    bool dfs(int cur, int pre, int &result, vector<bool> &hasApple)
    { // whether there exists red node below cur
        bool red = false;
        for (int &next : graph[cur])
            if (next != pre) // avoid go up
                if (dfs(next, cur, result, hasApple))
                {
                    result += 2; // go down and go back
                    red = true;
                }
        return red || hasApple[cur]; // red node below or cur is red node
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        graph.resize(n, vector<int>{});
        for (vector<int> &edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        int result = 0;
        dfs(0, -1, result, hasApple);
        return result;
    }
};