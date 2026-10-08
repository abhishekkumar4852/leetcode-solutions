class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Robot 1 at column 0
        // Robot 2 at column n-1
        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];

        for (int i = 1; i < m; i++) {

            vector<vector<int>> next(n, vector<int>(n, -1));

            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {

                    // Cherries collected in current row
                    int cherries = grid[i][j1];

                    if (j1 != j2)
                        cherries += grid[i][j2];

                    // 3 choices for robot 1
                    // 3 choices for robot 2
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int p1 = j1 + d1;
                            int p2 = j2 + d2;

                            if (p1 >= 0 && p1 < n &&
                                p2 >= 0 && p2 < n &&
                                dp[p1][p2] != -1) {

                                next[j1][j2] =
                                    max(next[j1][j2],
                                        dp[p1][p2] + cherries);
                            }
                        }
                    }
                }
            }

            dp = next;
        }

        int ans = 0;

        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                ans = max(ans, dp[j1][j2]);
            }
        }

        return ans;
    }
};