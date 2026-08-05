class Solution {
public:

    vector<int> ans ; 

    void check( int k , map<int,int>& indegree , vector<vector<int>>& v ,  vector<int>& vis ){

        ans.push_back( k ) ;

        for( int i = 0 ;  i < v[k].size() ; i++ ){

            if( vis[v[k][i]] == -1 ){

                vis[v[k][i]] = 1 ; 

                check( v[k][i] , indegree , v , vis ) ; 

            }

            indegree[v[k][i]] -- ; 
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> v(n) ; 

        map<int,int> indegree ; 

        for( auto i : invocations ){

            v[i[0]].push_back( i[1] ) ; 
            indegree[i[1]]++ ; 

        }

        
        vector<int> vis( n , -1 ) ;  // Visited Array
        vis[k] = 1 ; 
        check( k , indegree , v , vis ) ;

        for( int i = 0; i < ans.size() ; i ++ ){
            
            if( indegree[ans[i]] > 0 ){

                vector<int> result ; 

                for( int i = 0 ; i < n ; i++ ){
                    result.push_back(i) ;
                }

                return result ; 
            }
        }

        vector<int> result ; 

        for( int i = 0 ; i < n ; i++ ){

            if( vis[i] == -1 ){
                result.push_back(i) ;
            }
        }

        return result ; 
        
    }
};