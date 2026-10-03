class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build graph
        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // Dijkstra
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto [nextNode, wt] : adj[node]) {

                if (time + wt < dist[nextNode]) {

                    dist[nextNode] = time + wt;

                    pq.push({
                        dist[nextNode],
                        nextNode
                    });
                }
            }
        }

        // Find maximum shortest distance
        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};