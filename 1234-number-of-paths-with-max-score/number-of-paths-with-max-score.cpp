class Solution {
public:

    // DP : BOTTOM UP Approach 
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        const int MOD = 1e9 + 7;

        // dpScore[i][j] = maximum score from E to (i,j)
        // dpPath[i][j] = number of maximum-score paths
        vector<vector<int>> dpScore(n, vector<int>(n, -1));
        vector<vector<int>> dpPath(n, vector<int>(n, 0));

        dpScore[0][0] = 0;
        dpPath[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'X') continue;
                if(i == 0 && j == 0) continue;

                int bestScore = -1;
                int ways = 0;

                // from up
                if(i > 0 && dpPath[i-1][j] > 0) {
                    if(dpScore[i-1][j] > bestScore) {
                        bestScore = dpScore[i-1][j];
                        ways = dpPath[i-1][j];
                    } else if(dpScore[i-1][j] == bestScore) {
                        ways = (ways + dpPath[i-1][j]) % MOD;
                    }
                }

                // from left
                if(j > 0 && dpPath[i][j-1] > 0) {
                    if(dpScore[i][j-1] > bestScore) {
                        bestScore = dpScore[i][j-1];
                        ways = dpPath[i][j-1];
                    } else if(dpScore[i][j-1] == bestScore) {
                        ways = (ways + dpPath[i][j-1]) % MOD;
                    }
                }

                // from diagonal
                if(i > 0 && j > 0 && dpPath[i-1][j-1] > 0) {
                    if(dpScore[i-1][j-1] > bestScore) {
                        bestScore = dpScore[i-1][j-1];
                        ways = dpPath[i-1][j-1];
                    } else if(dpScore[i-1][j-1] == bestScore) {
                        ways = (ways + dpPath[i-1][j-1]) % MOD;
                    }
                }

                if(ways == 0) continue;

                int val = 0;
                if(board[i][j] != 'S' && board[i][j] != 'E')
                    val = board[i][j] - '0';

                dpScore[i][j] = bestScore + val;
                dpPath[i][j] = ways;
            }
        }

        if(dpPath[n-1][n-1] == 0)
            return {0,0};

        return {dpScore[n-1][n-1], dpPath[n-1][n-1]};
    }
};
        
