class Solution {
public:
    int n, m;

    void dfs(int row, int col, vector<vector<char>>& board) {

        // Boundary check
        if (row < 0 || row >= n ||
            col < 0 || col >= m ||
            board[row][col] != 'O') {
            return;
        }

        // Mark safe O
        board[row][col] = '#';

        // Explore 4 directions
        dfs(row - 1, col, board);
        dfs(row + 1, col, board);
        dfs(row, col - 1, board);
        dfs(row, col + 1, board);
    }

    void solve(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();

        // Step 1: Traverse first and last columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        // Step 2: Traverse first and last rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }

        // Step 3: Convert remaining O to X
        // Restore safe # to O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};