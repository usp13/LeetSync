class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string s = "123456789" ;
        int n = s.length() ;  
        vector<int> ans ; 

        for( int i = 2 ; i <= n ; i++ ){
            for( int start = 0 ; start <= n - i ; start++ ){

                string temp = s.substr( start , i ) ; 

                int poss = stoi( temp ) ; 

                if( poss >= low && poss <= high ){
                    ans.push_back(poss) ; 
                }

            }
        }

        return ans ; 
    }
};