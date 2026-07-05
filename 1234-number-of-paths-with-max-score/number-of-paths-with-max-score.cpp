class Solution {
public:
    int n;
    const int modd = 1e9 + 7;
    vector<vector<pair<int,int>>> dp;

    int getIntFromChar(char ch){
        return (ch == 'S' || ch == 'E') ? 0 : ch - '0';
    }

    bool isvalid(int i, int j, vector<string>& board){
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    // DP : Recursion + Memoisation ! 

    pair<int,int> solve(int i, int j, vector<string>& board){

        // {score, paths}
        if(board[i][j] == 'E')
            return {0,1};

        if(board[i][j] == 'X')
            return {0,0};

        if(dp[i][j] != make_pair(-1,-1))
            return dp[i][j];

        // initialize scores as -1
        int upscore = -1, leftscore = -1, diascore = -1;
        int uppath = 0, leftpath = 0, diapath = 0;

        char ch = board[i][j];

        // Up
        if(isvalid(i-1, j, board)){
            auto [score, path] = solve(i-1, j, board);
            if(path){
                upscore = score + getIntFromChar(ch);
                uppath = path;
            }
        }

        // Left
        if(isvalid(i, j-1, board)){
            auto [score, path] = solve(i, j-1, board);
            if(path){
                leftscore = score + getIntFromChar(ch);
                leftpath = path;
            }
        }

        // Diagonal
        if(isvalid(i-1, j-1, board)){
            auto [score, path] = solve(i-1, j-1, board);   // FIXED
            if(path){
                diascore = score + getIntFromChar(ch);
                diapath = path;
            }
        }

        // No valid path
        if(uppath == 0 && leftpath == 0 && diapath == 0)
            return dp[i][j] = {0,0};

        int bestscore = max({upscore, leftscore, diascore});
        int bestpath = 0;

        if(upscore == bestscore)
            bestpath = (bestpath + uppath) % modd;

        if(leftscore == bestscore)
            bestpath = (bestpath + leftpath) % modd;

        if(diascore == bestscore)
            bestpath = (bestpath + diapath) % modd;

        return dp[i][j] = {bestscore, bestpath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();

        dp.assign(n, vector<pair<int,int>>(n, {-1,-1}));

        auto ans = solve(n-1, n-1, board);

        if(ans.second == 0)
            return {0,0};

        return {ans.first, ans.second};
    }
};