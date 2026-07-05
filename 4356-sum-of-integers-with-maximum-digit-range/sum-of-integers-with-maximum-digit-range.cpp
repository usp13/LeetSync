class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int n = nums.size() ; 
        int maxr = -1 ; 
        int sum = 0 ; 

        for( int i = 0 ; i < n ; i++  ){

            int num = nums[i] ; 
            int maxi= 0 ;
            int mini = 9 ;

            while( num > 0 ){

                int d = num % 10 ;
                 maxi = max( maxi , d ) ; 
                 mini = min( mini , d) ;
                num = num / 10 ;
            }

            int r = ( maxi - mini ) ; 

            if( r > maxr ){
                maxr = r  ;
                sum = nums[i] ;
            }
            else if( maxr == r ){
                sum += nums[i] ; 
            }
            
    
        }

        return sum  ;
        
    }
};