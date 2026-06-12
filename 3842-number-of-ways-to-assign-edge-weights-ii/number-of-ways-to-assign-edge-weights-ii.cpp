class Solution {
public:

    int MODD = 1e9 + 7 ;
    int LOG ;  
    long long modpow( long long a , long long b ){

        long long ans = 1 ; 

        while( b > 0 ){

            if( b & 1 ){
                ans =  ( ans*a ) % MODD ;
            }

            a = ( a*a ) % MODD ; 

            b >>= 1 ; 
        }
        return ans  ; 
    }

    void dfs( int node , int parent , vector<vector<int>>& adj, vector<int>& depth , vector<vector<int>>& up ){

        up[node][0] = parent ; 

        for( int i = 1 ; i < LOG ; i++ ){
            up[node][i] = up[up[node][i-1]][i-1] ; 
        }

        for( int neighbour : adj[node] ){

            if( neighbour == parent ) continue ; 

            depth[neighbour] = depth[node] + 1 ;

            dfs( neighbour , node , adj , depth , up) ; 
        }
    }

    // LOWEST COMMON ANCESTOR
    int LCA( int u , int v , vector<int> &depth ,  vector<vector<int>>& up ){

        if( depth[u] < depth[v] ){
            swap(u,v) ;
        }

        int diff = depth[u] - depth[v] ;
        // Bringing biht the node to the same depth

        for( int i = LOG - 1 ; i >= 0 ; i-- ){

            if( diff & (1<<i) ){
                u = up[u][i] ; 
            }
        }

        // COMMON ANCESTOR
        if( v == u ) return u ; 

        // Binary Lifting until we dont get common ancestor
        for( int i = LOG - 1 ; i >= 0 ; i-- ){
            
            if( up[u][i] != up[v][i] ){
               
                u = up[u][i] ; 
                v = up[v][i] ; 

            }
        }
        
        return up[u][0] ;
 
    }


    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {

        int n = edges.size() + 1 ; 

        LOG = 1 ; 
        while( ( 1<< LOG ) <= n ) LOG ++ ; 

        vector<vector<int>> adj( n + 1 ) ; 

        for( auto & e : edges ){

            int u = e[0] ; 
            int v = e[1] ; 

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;

        }

        vector<int> depth( n + 1 , 0 ) ; 

        vector<vector<int>> up( n + 1 , vector<int>( LOG , 0)) ; 

        dfs( 1 , 0 , adj , depth , up ) ;
        
        vector<int> ans ; 

        for( auto & q : queries ){
            int u = q[0] ; 
            int v = q[1] ; 

            int l = LCA( u , v , depth , up ) ; 

            long long dist = depth[u] + depth[v] - 2LL * depth[l] ; 

            if( dist == 0 ){
                ans.push_back(0) ;
            }
            else {
                ans.push_back(modpow(2, dist - 1 )) ;

            }
        }

        return ans; 

        

        
    }
};