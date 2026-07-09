class Solution {
public:
    bool isPalindrome(int x) {

        auto n = x ;
        if ( x < 0 ){
            return false;
        } 

        long long int number = 0 ;

        while ( x!= 0 ){
            number = number*10 ;
            number = number + (x%10) ;
            x = x / 10 ;
        }

        if (number == n){
            return true ;
        }

        return false ;

        
    }
};