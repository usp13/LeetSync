class Solution {
public:
    bool closeStrings(string word1, string word2) {

        int n = word1.length() ;
        int m = word2.length() ;

        if( m != n) return false;

        // freq map as no char should present that is presemt in only one word
        // the frequency should be same for both of the words

        vector<int> f1( 26,0) ; // for word 1 
        vector<int> f2( 26,0) ; // for word 2

        for( int i = 0 ; i < n ; i++){

            // index = word[i] - 'a'
            f1[word1[i] - 'a']++ ;

        }
        for( int i = 0 ; i < m ; i++){
            
            f2[word2[i] - 'a']++ ;

        }

        //1st intuition : word in w1 shuld be eq to w2
        for( int i = 0 ; i < 26 ; i++){

            if( f1[i] != 0 &&  f2[i] != 0){
                continue ;
            }

            if( f1[i] == 0 &&  f2[i] == 0){
                continue ;
            }

            return false;

        }

        //intuition 2 : frequencies  of chars in w1 and w2 should be equal irrespective of their char

        sort( begin(f1) , end(f1)) ;
        sort( begin(f2) , end(f2)) ; 

        return f1 == f2 ; 

    }
};