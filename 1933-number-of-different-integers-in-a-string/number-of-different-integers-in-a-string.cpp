class Solution {
public:
    int numDifferentIntegers(string word) {
        
        int n = word.size() ; 
        set<string> st ; 

        for( int i = 0 ; i < n ; i++){
            if( word[i] >= '0' && word[i] <= '9' ){ // number 
               
                string num = "" ; // complete number

                while( i < n && word[i] >= '0' && word[i] <= '9' ){
                    num += word[i] ; 
                    i++ ; 
                }

                int j = 0 ; 

                // Removing leding zeros
                while( j < num.size() -1 && num[j] == '0'){
                    j++ ;
                }

                num = num.substr(j) ; 

                st.insert(num) ; // insert in set
            }
        }

        return st.size() ;
    }
};