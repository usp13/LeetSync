class Solution {
public:
    int modd = 1e9 + 7 ; 

    long long modpow( long long a , long long b , long long modd ){

        long long ans = 1 ; 

        while( b > 0 ){
             
            if( b % 2 == 1 ){
                ans = ( ans % modd *  a % modd ) % modd ;
            }

            b = b/2 ; 

            a = (( a % modd ) * ( a % modd )) % modd ;
        }

        return ans ; 
    }
      
    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        int n = edges.size() ; 

        vector<int> adj[100001] ;

        for( auto it : edges ){

            adj[it[0]].push_back( it[1] ) ; 
            adj[it[1]].push_back( it[0] ) ; 

        }

        queue<pair<int,int>> q ; 

        int level = 0 ; 
         
        q.push({1,-1}) ; 

        while( !q.empty() ){

            int size = q.size() ;

            while( size -- ){

                auto it = q.front() ; 
                q.pop() ; 

                for( auto itr : adj[it.first]){

                    if( itr != it.second ){
                        q.push( { itr, it.first }) ; 
                    }
                }
            }

            level ++ ; 
        }

        level -- ; 

        long long ans = modpow( 2 , level - 1 , modd ) ; 

        return ans ; 
    }
};