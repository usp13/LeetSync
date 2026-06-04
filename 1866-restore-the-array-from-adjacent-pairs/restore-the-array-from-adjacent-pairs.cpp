class Solution {
public:
    vector<int> ans ; 

        
    void dfs( int a , int prev ,  unordered_map<int,vector<int>>& mp  ){

        ans.push_back( a ) ; // Pusing First element

        for( int &v : mp[a] ){ // traversing in the adjecency list of the element
            if( v != prev ){
                dfs( v , a , mp ) ; // RECURSION 
            }

        }

    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        int n = adjacentPairs.size() ; 

        // Adjacency List in HASH MAP 

        unordered_map<int,vector<int>> mp ; 

        for( vector<int> & v : adjacentPairs ){

            int a = v[0] ;
            int b = v[1] ;

            mp[a].push_back(b) ; 
            mp[b].push_back(a) ; 

        }

        int start = -1 ; // starting point  

        for( auto &it : mp ){

            if( it.second.size() == 1 ){ // has only one neighbour 

                start = it.first ; 
                break  ;

            }
        }

        dfs( start , INT_MIN , mp );

        return ans ;

        
    }
};