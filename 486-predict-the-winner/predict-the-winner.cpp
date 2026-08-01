class Solution {
public:

    int dp[25][25] ; 
    // DP : Recursion + Memoization
    int solve(int i , int j , vector<int>& nums ){

        if( i > j ){
            return 0 ; 
        }
        if( i == j ){
            return nums[i] ; 
        }

        if( dp[i][j] != -1 ){
            return dp[i][j] ; 
        }

        // After Player 1 takes the i'th or j'th element , Player 1 will be left with WORST/Smallest element that was ignored by Player 2 

        // Min() => taken becuase we are expecting the worst 

        int take_i = nums[i] + min( solve(i+2,j,nums) , solve( i+1 , j-1,nums)) ; 

        int take_j = nums[j] + min( solve(i+1,j-1, nums) , solve(i, j-2 , nums) ) ;


        return  dp[i][j] = max( take_i , take_j) ;  

    } 
    bool predictTheWinner(vector<int>& nums) {
        
        /*When its your turn, DO YOUR BEST !
        When it's your oppenent's turn , EXPECT the WORST !*/

        // Considering all the possible paths of Player 1 Only

        int n = nums.size() ; 

        memset( dp , -1 , sizeof(dp)) ; 

        int totalscore = accumulate( nums.begin() , nums.end() , 0 ) ; 

        int player1score = solve( 0 , n-1 , nums) ; 
        
        int player2score = totalscore - player1score ; 

        if( player1score >= player2score ){ // if player1 wins !!!
            return true ; 
        }
        else {
            return false ; 
        }



    }
};