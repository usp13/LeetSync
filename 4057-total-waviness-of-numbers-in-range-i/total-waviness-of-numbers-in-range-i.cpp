class Solution {
public:
    int totalWaviness(int num1, int num2) {

        //USP
        int total = 0 ;

        for( int n = num1 ; n <= num2 ; n++){
            int p = n  ;

            if( p < 100){
                continue ;
            }

            string s = to_string(p) ; // Con
            int w = 0 ; // Waviness
            int m = s.size() ;

            for( auto i = 1 ; i  < m - 1 ; i++){
                if ((s[i] > s[i-1] && s[i] > s[i+1]) 
                || (s[i] < s[i-1] && s[i] < s[i+1]) ) { // checking the middle digit to be a valley or Peak
                    w++ ;
                }

            }

            total += w ;


        }

        return total ;
      
        
    }
};