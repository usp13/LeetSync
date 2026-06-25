class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size() ;
        // Boyer-Moore Algorithm

        // ⌊n / 2⌋ times -> Max 1 majority element possible 
        // ⌊n / 3⌋ times -> Max 2 majority elements possible 
        //......
        // ⌊n / k⌋ times -> Max 2\k majority elements possible

        int count = 1 ; 
        int majority = nums[0] ;

        for( int i = 1 ; i < n ; i++ ){

            if( count == 0 ){
                majority = nums[i] ;
                count = 1 ;
            }
            else if( nums[i] == majority ){
                count ++ ;
            }
            else {
                count -- ;
            }
        }

        return majority ; 

    }
};