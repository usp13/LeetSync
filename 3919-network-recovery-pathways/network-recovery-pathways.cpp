class Solution {
public:

    bool check( long long mid , vector<vector<pair<int,int>>>& adj , vector<int> &topo , vector<bool> &online, long long k , int n  ){

        const long long infinity = 1e18 ;

        vector<long long> dist( n , infinity ) ; 
        dist[0] = 0  ;

        for ( int u : topo ){

            if( dist[u] == infinity ){
                continue ;
            }

            if( u != 0 && u != n-1 && !online[u] ){
                continue ; 
            }

            for( auto &[v,w] : adj[u] ){

                if( w < mid ) continue  ;
                if( v != n-1 && !online[v] ) continue ; 

                dist[v] = min( dist[v] , dist[u] + w ) ; 
            }
        }

        return ( dist[n-1] <= k ) ;

    }
    

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size() ; 

        vector<vector<pair<int,int>>> adj(n) ; 

        vector<int> indegree( n , 0 ) ; 

        int maxi = 0 ; 

        for( auto &e : edges ){

            int u = e[0] ;
            int v = e[1] ;
            int w = e[2] ;

            adj[u].push_back( { v, w } ) ; 

            indegree[v]++ ; 
            maxi = max( maxi , w ) ; 
        }

        // Topological Sort
        queue<int> q ; 
        for( int i = 0 ; i < n ; i++ ){
            if( indegree[i] == 0 ){
                q.push(i) ;
            }
        }

        vector<int> topo ; 

        while( !q.empty() ){

            int u = q.front() ; 
            q.pop()  ;
            topo.push_back(u) ; 

            for( auto &[v,w] : adj[u] ){
                if( -- indegree[v] == 0 ){
                    q.push(v) ; 
                }
            }
        }

        long long l = 0 ; // low
        long long h = maxi ; // high
        int ans = -1 ; 


        // Binary Search
        while( l <= h ){

            long long mid = l + ( h-l )/2 ;


            if( check( mid , adj , topo , online , k , n )){
                ans = mid ; 
                l = mid + 1 ; 
            } 
            else {
                h = mid - 1  ;
            }

        } 
        
        return ans ; 
        
    }
};