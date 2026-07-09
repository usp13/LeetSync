/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        // BINARY SEARCH 
        int l = 0 ; 
        int r = n ; 

        while( l <= r ){

            int mid = l + (r-l) / 2 ; // the Guess

            int value = guess( mid ) ; //Given that  You call a pre-defined API

            if( value == 0 ){
                return mid ; // correct ans
            }
            else if( value == -1 ){
                r = mid - 1 ;
            }
            else {
                l = mid + 1 ; 
            }
        }

        return -1 ; 


        
    }
};