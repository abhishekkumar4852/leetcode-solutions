class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& safe) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int nei : graph[node]) {

            // Not visited
            if (!vis[nei]) {
                if (dfs(nei, graph, vis, pathVis, safe)) {
                    return true;   // cycle found
                }
            }

            // Visited in current DFS path -> cycle
            else if (pathVis[nei]) {
                return true;
            }
        }

        // No cycle found from this node
        pathVis[node] = 0;
        safe[node] = 1;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> safe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, safe);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};