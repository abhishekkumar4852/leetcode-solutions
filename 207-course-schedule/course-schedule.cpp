class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Step 1: Build adjacency list
        for (auto it : prerequisites) {

            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Step 2: Push all nodes having indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Step 3: BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 4: Check if all courses completed
        return count == numCourses;
    }
};