class Solution {
public:

    int solvelowerbound( int l , int r , vector<int>& potions , int minpotion  ){

        // Binary Search
        int possibleidx = -1 ; 

        int mid = 0 ; 

        while( l <= r ){

            mid = l + (r-l) / 2 ; 

            if( potions[mid] >= minpotion ){
                possibleidx = mid ; 
                r = mid - 1 ; 
            }
            else {
                l = mid + 1 ; 
            }

        }

        return possibleidx ; 
    }

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

            int idx = solvelowerbound( 0 , n-1 , potions , minpotion ) ; 
            //Custon made lower bound method 

            int count = n - idx ; 

            ans.push_back(count) ;
        }

        return ans ; 
    }
};