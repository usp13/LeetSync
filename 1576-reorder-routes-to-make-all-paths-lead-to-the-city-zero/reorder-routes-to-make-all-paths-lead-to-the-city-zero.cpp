class Solution {
public:

    int count = 0  ;

    void dfs( int u , int parent ,unordered_map<int , vector<pair<int,int>>> &adj){

        for( auto &p : adj[u] ){

            int v = p.first ; 
            int check = p.second ;  // if check == '1' then Original edge , if '0' then Duplicate edge

            if( v != parent ){

                if( check == 1 ){
                    count++ ; 
                }

                dfs( v , u , adj ) ; 
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        unordered_map<int , vector<pair<int,int>>> adj ; // Adjecentcy vector

        for( auto &vec : connections ){

            int a = vec[0] ; 
            int b = vec[1] ;

            adj[a].push_back( {b,1} ) ; // Original edge from 'a' to 'b' denoted by "1" !
            
            adj[b].push_back( {a,0} ) ; // Duplicate edge from 'b' to 'a' denoted by "0" , that we made it  !


        }

        dfs( 0 , -1 , adj ) ; 

        return count ; 
        
    }
};