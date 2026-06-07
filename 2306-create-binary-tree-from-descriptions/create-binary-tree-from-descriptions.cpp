/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        // Keeping the track of all possible roots in a map , then verify by checking wheather they are child of any node or not !

        unordered_map<int,TreeNode*> mp ; //Map to store all the nodes and it's children

        unordered_set<int> childset ; // The nodes that can become roots, as they are leafnodes to some root  

        // descriptions[i] = [parent , child, isLeft]
        for( vector<int>& arr : descriptions ){

            int parent = arr[0] ; 
            int child = arr[1] ;
            int isleft = arr[2] ; 

            if( mp.find(parent) == mp.end() ){ // if not present , create a new parent node 
                mp[parent] = new TreeNode( parent ) ; 
            }

            if( mp.find(child) == mp.end() ){ // If not present , create a new node
                mp[child] = new TreeNode( child ) ; 
            }

            if( isleft == 1 ){ // 1 means this is the left child
                mp[parent] -> left = mp[child] ; 

            }
            else { // Right child
                mp[parent] -> right = mp[child] ; 

            }

            childset.insert(child) ; // Putting in the set


        }

        // Traversal for finding ROOT
        for( vector<int>& arr : descriptions ){

            int parent = arr[0] ; 

            if( childset.find( parent ) == childset.end() ){ // if parent is found in child's set , it will be the root 
                return mp[parent] ;
            }

        }

        //if not present , return NULL 
        return NULL ; 



    }
};