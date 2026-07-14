class Solution {
public:

              
    void dfs( unordered_map<string, vector<pair<string,double>>> &adj , string src , string dest ,  unordered_set<string> &visited , double product , double &ans   ){

        if( visited.find(src) != visited.end() ){
            return ; // not found 
        }

        visited.insert(src) ; // mark as visited 

        if( src == dest ){
            ans = product ; 
            return ;
        }

        for( auto &p : adj[src] ){

            string v = p.first ; 
            double val = p.second ; 

            dfs( adj , v , dest , visited , product*val , ans ) ;
        }
    }




    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size() ;

        unordered_map<string, vector<pair<string,double>>> adj ; 

        for( int i = 0 ; i < n ; i++ ){

            string u = equations[i][0] ; // a
            string v = equations[i][1] ; // b
            double value  = values[i] ; 

            adj[u].push_back( { v , value }) ; // a / b 
            adj[v].push_back( { u , 1.0 / value }) ; // b / a  

        }

        vector<double> result ; 

        for( auto &q : queries ){

            string src = q[0] ; // Source
            string dest = q[1] ; // Destination 

            double ans = -1.0 ; 
            double product = 1.0 ; 

            if( adj.find(src) != adj.end() ){

                unordered_set<string> visited ; 

                dfs(adj , src , dest , visited , product , ans ) ; 
            }

            result.push_back(ans) ;
        }

        return result  ;

        
    }
};