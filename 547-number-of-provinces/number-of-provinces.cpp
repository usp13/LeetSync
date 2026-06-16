class Solution {
public:

        
    void bfs( unordered_map<int,vector<int>> mp , int u , vector<bool>& visited ){

        queue<int> q;

        q.push(u) ; 
        visited[u] = true  ;

        while( !q.empty() ){
            int curr = q.front() ; 
            q.pop() ; 

            for( int &v : mp[curr] ){
                if( !visited[v] ){
                    bfs( mp , v , visited ) ; 
                }
            }

        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size() ; 

        unordered_map<int , vector<int>> mp ; // Map for adjacency

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( isConnected[i][j] == 1 ){

                    mp[i].push_back(j) ; 
                    mp[j].push_back(i) ; 

                }
            }
        }
        
        vector<bool> visited(  n , false ) ; 
        int count = 0 ; 

        for( int i = 0 ; i < n ; i++ ){

            if( !visited[i] ){
                bfs( mp , i , visited ) ;
                count++ ; 
            }
        }

        return count ; 
    }
};