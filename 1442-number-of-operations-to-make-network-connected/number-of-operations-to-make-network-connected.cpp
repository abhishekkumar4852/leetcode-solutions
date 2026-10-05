class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        // Already connected → redundant cable
        if (pa == pb)
            return false;

        if (rank[pa] < rank[pb])
            parent[pa] = pb;
        else if (rank[pa] > rank[pb])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }

        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Minimum cables required to connect n computers
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &edge : connections) {
            if (unite(edge[0], edge[1])) {
                components--;
            }
        }

        return components - 1;
    }
};