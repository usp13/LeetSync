class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int countone = 0 ; 
        int flips = 0 ; 

        for( char &ch : s ){
            if( ch == '1'){
                countone ++ ;
            }
            else {
                flips = min( flips + 1 , countone ) ; 
            }
        }
        
        return flips ; 
    }
};