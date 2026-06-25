class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size() ;
        // Boyer-Moore Algorithm

        // ⌊n / 2⌋ times -> Max 1 majority element possible 
        // ⌊n / 3⌋ times -> Max 2 majority elements possible 
        //......
        // ⌊n / k⌋ times -> Max 2\k majority elements possible

        int count1 = 0 ;
        int count2 = 0 ; 

        int majority1 = NULL ;
        int majority2 = NULL ;


        for( int i = 0 ; i < n ; i++ ){

            if( nums[i] == majority1 ){
                count1 ++ ;
            }
            else if( nums[i] == majority2 ){
                count2 ++ ;
            }
            else if( count1 == 0 ){
                majority1  = nums[i] ; 
                count1 = 1 ;
            }
            else if( count2 == 0 ){
                majority2  = nums[i] ; 
                count2 = 1 ;

            }
            else {
                count1 -- ;
                count2 -- ;

            }
        }

        // VERIFICATION
        vector<int> majorityvec ;
        int f1 = 0 ;
        int f2 = 0 ; 


        for( int &num : nums ){

            if( num == majority1 ){
                f1++ ;
            }
            else if(num == majority2 ){
                f2++ ;
            }
        }

        if( f1 > floor(n/3) ){
            majorityvec.push_back( majority1) ;
        }
        if( f2 > floor(n/3) ){
            majorityvec.push_back( majority2) ;
        }

        return majorityvec ; 

        
    }
};