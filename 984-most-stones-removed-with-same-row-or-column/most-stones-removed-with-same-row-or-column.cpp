class Solution {
public:

    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        // Coordinates are <= 10^4
        int OFFSET = 10001;

        parent.resize(20005);
        rank.assign(20005, 0);

        for (int i = 0; i < 20005; i++)
            parent[i] = i;

        unordered_set<int> nodes;

        // Connect row and column
        for (auto &stone : stones) {

            int row = stone[0];
            int col = stone[1] + OFFSET;

            unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        // Count connected components
        unordered_set<int> components;

        for (int node : nodes) {
            components.insert(find(node));
        }

        return n - components.size();
    }
};