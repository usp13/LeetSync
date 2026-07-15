class Solution {
public:
    vector<vector<int>> directions{ {0,1} , {0,-1} , {1,0} , {-1,0} } ; // Right , left , Up , Down 

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size() ; 
        int n = maze[0].size() ; 

        queue<pair<int,int>> q ; // queue of the coordinates of maze
        maze[entrance[0]][entrance[1]] = '+' ; // visited

        int steps = 0 ;

        //BFS
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

            while(!q.empty()){

                int sz = q.size();

                while(sz--){

                    auto [i, j] = q.front();
                    q.pop();

                    if((i != entrance[0] || j != entrance[1]) &&
                    (i == 0 || i == m-1 || j == 0 || j == n-1))
                        return steps;

                    for(auto &dir : directions){

                        int i1 = i + dir[0];
                        int j1 = j + dir[1];

                        if(i1 >= 0 && i1 < m &&
                        j1 >= 0 && j1 < n &&
                        maze[i1][j1] != '+'){

                            maze[i1][j1] = '+';
                            q.push({i1, j1});
                        }
                    }
                }

                steps++;
            }

        return -1;
       
    }
        

  
};