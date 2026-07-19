class Solution {
public:
    bool visited[8][8][2];

    bool canReach(vector<int>& start, vector<int>& target)
    {
        return dfs(start[0], start[1], 0, target);
    }

    // DFS Approach 
    bool dfs(int i, int j, int steps, vector<int>& target)
    {
        if (i < 0 || i >= 8 || j < 0 || j >= 8)
        {
            return false;
        }

        int carry = steps % 2;

        if (visited[i][j][carry])
        {
            return false;
        }

        visited[i][j][carry] = true;

        if (i == target[0] && j == target[1])
        {
            return carry == 0;
        }

        vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};

        vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int k = 0; k < 8; k++)
        {
            if (dfs (i + dx[k], j + dy[k], steps + 1, target))
            {
                return true;
            }
        }

        return false;
    }
};