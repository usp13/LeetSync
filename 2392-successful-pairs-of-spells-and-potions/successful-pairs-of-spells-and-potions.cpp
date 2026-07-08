class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int m = spells.size() ; 
        int n = potions.size() ; 

        sort( potions.begin() , potions.end()) ; 

        int maxpotion = potions[n-1] ; 

        vector<int> ans ;

        for( int i = 0 ; i < m ; i++ ){

            int spell = spells[i] ; 

            long long minpotion = ceil( (1.0*success) / spell ) ; 

            if( minpotion > maxpotion ){
                ans.push_back(0) ;
                continue ; 
            }

            int idx = lower_bound( potions.begin() , potions.end() , minpotion ) - potions.begin() ; 
            // Built-in cpp STL

            int count = n - idx ; 

            ans.push_back(count) ;
        }

        return ans ; 
    }
};