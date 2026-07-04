class Solution {
public:
    void dfs( int u ,  unordered_map<int,vector<pair<int,int>>> &adj , vector<bool> &visited , int &ans  ){

        visited[u] = true ; 

        // go for u's neighbour
        for( auto &p : adj[u] ){

            int v = p.first ; // destination
            int d = p.second ; // dist

            ans = min( ans , d ) ; 

            if( !visited[v] ){
                dfs(v , adj , visited , ans ) ; 
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        //The score of a path between two cities is defined as the minimum distance of a road in this path.

        unordered_map<int,vector<pair<int,int>>> adj  ;

        for( auto &vec : roads ){

            int u = vec[0] ; // source
            int v = vec[1] ; // destination
            int d = vec[2] ; //distance

            adj[u].push_back( { v, d } ) ; 
            adj[v].push_back( { u, d } ) ; 


        }

        vector<bool> visited( n , false ) ; 

        int ans = INT_MAX ; 

        dfs( 1 , adj , visited , ans ) ;

        return ans ; 

        
    }
};