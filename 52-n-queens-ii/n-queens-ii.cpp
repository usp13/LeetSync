class Solution {
public:

    /*
    Same as number of valid N-Queens arrangements (SAME AS  LeetCode 5: N-Queens I) , in that we returned app possible ways as a vector, here just the number of possible arrangements.
    */
    int N;
    int ans = 0;

    bool isvalid(vector<string>& board, int row, int col) {

        // Check same column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row) {

        if (row == N) {
            ans++;
            return;
        }

        for (int col = 0; col < N; col++) {

            if (isvalid(board, row, col)) {

                board[row][col] = 'Q';

                solve(board, row + 1);

                board[row][col] = '.';
            }
        }
    }

    // Backtracking
    int totalNQueens(int n) {

        N = n;

        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return ans;
    }
};