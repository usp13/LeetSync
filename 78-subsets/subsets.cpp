class Solution {
public:

    vector<vector<int>> ans ; 

    void solve( int i , vector<int>& nums , vector<int>& temp ){

        if( i >= nums.size() ){
            ans.push_back(temp) ; 
            return ;
        }

        temp.push_back( nums[i] ) ; // Take the i'th element
        solve( i+1 , nums , temp ) ; // RECURSION
        
        temp.pop_back() ; // NOT take i'th element
        solve( i+1 , nums , temp ) ; // RECURSION


    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size() ;  

        vector<int> temp ;   

        solve( 0 , nums , temp ) ; 

        return ans ; 
        
    }
};