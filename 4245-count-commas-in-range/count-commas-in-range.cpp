class Solution {
public:
    int countCommas(int n) {
        
        //for every 3 digits added, a new comma is added

        if( n < 1000){
            return 0 ;
        }

        return n - 999 ; 

    }
};