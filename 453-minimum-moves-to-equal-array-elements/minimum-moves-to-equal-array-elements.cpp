class Solution {
public:
    int minMoves(vector<int>& nums) {

        int low = ranges::min(nums) ; 

        int  moves = 0;
        
        for (int x : nums) {
            moves += x - low ;
        }

        return moves;
    }
};