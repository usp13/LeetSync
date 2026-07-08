class Solution {
public:
    int modd = 1e9 + 7 ; 

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        

        int n = s.length()  ;

        vector<int> nonzerocount (n,0) ;
        vector<long long> numberupto( n , 0) ; 
        vector<long long> digitsumupto( n , 0) ; 
        vector<long long> pow10( n+1 , 0) ; 

        // Power of 10 
        pow10[0] = 1 ; 
        for( int i = 1 ; i <= n ; i++ ){

            pow10[i] = ( pow10[i-1]*10) % modd ; 
        }

        // Non zero count
        nonzerocount[0] = ( s[0] != '0' ) ? 1 : 0 ;

        for( int i = 1 ; i < n ; i++ ){

            int digit = s[i] - '0' ;
            nonzerocount[i] = nonzerocount[i-1] + ( digit != 0 ? 1 : 0 ) ; 

            
        }

        // Number Upto 
        numberupto[0] = s[0] - '0' ;

        for( int i  = 1 ; i < n ; i++ ){

            int digit = s[i] - '0' ;

            if( digit != 0 ){
                numberupto[i] = ( numberupto[i-1]*10 + digit) % modd ; 
            }
            else {
                numberupto[i] = ( numberupto[i-1] ) ; 
            }
        }

        // DIGIT sum upto 
        digitsumupto[0] = s[0] - '0' ; 

        for( int i = 1 ; i < n ; i++ ){
            int digit = s[i] - '0' ;
            digitsumupto[i] =  digitsumupto[i-1] + digit ;  
        }


        // Query 

        int q = queries.size() ; 

        vector<int> ans(q) ; 

        for( int i = 0 ; i < q ; i++ ){

            int l = queries[i][0] ; 
            int r = queries[i][1] ;

            // sum =  digitsumupto[r] -  digitsumupto[l-1]
            long long sum = digitsumupto[r] - ((l == 0) ? 0 : digitsumupto[l-1] ) ;  

            int numbefore = ( l == 0 ) ? 0 : numberupto[l-1] ; 

           int k = nonzerocount[r] - ((l == 0) ? 0 : nonzerocount[l-1]);

            long long x = ( ( numberupto[r] ) - (numbefore * pow10[k] % modd) + modd  ) % modd ; 

            ans[i] = (int) (( x * sum ) % modd) ; 
        }
         

        return ans ; 


    }
};