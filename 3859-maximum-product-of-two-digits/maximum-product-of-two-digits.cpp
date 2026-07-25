class Solution {
public:
    int maxProduct(int n) {
        
        int maxdigit = 0 ;
        
        int secondmaxdigit = 0 ; 

        int num = n ; 

        while (num > 0) {

            int digit = num % 10 ; //leftmost digit

            num = num / 10 ; // remove leftmost digit

            if( digit > maxdigit ){
               
                secondmaxdigit = maxdigit ; //2nd max = max

                maxdigit = digit ; // max = digit
            }

            else if( digit > secondmaxdigit ){
            
                secondmaxdigit = digit ; //2nd max = digit

            }


        }

        return  ( maxdigit * secondmaxdigit ) ; 

    }
};