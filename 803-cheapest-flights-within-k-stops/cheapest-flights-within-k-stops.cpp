class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // K stops means maximum K+1 edges
        for (int i = 0; i <= k; i++) {

            // Copy is important
            vector<int> temp = dist;

            for (auto &flight : flights) {

                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != INT_MAX &&
                    dist[u] + price < temp[v]) {

                    temp[v] = dist[u] + price;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};