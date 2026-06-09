class Solution {
public:


    int findfirst(vector<int>& nums ,int target){

        int n = nums.size() ; 
        int l = 0;
        int r = n - 1;
        int answer = -1 ;

        // Binary Search for Searching first occurance 
        while ( l<=r ){

            int mid =  l + ( r - l ) /2 ;

                if(nums[mid] == target){
                    answer = mid ;
                    r = mid - 1 ;
                    
                }
                else if( nums[mid] < target ){
                    l = mid + 1 ;
                }
                else {
                    r = mid - 1 ;
                }
        }
        return answer ;
    }


    int findlast(vector<int>& nums ,int target){

        int n = nums.size() ; 
        int l = 0;
        int r = n - 1;
        int answer = -1 ;

        // Binary Search for Searching last occurance 
        while ( l<=r ){

            int mid = l + ( r - l ) /2 ;

                if(nums[mid] == target){
                    answer = mid ;
                    l = mid + 1 ;
                    
                }
                else if( nums[mid] < target ){
                    l = mid + 1 ;
                }
                else {
                    r = mid - 1 ;
                }
        }
        return answer ;
    }
   

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findfirst( nums , target) ; 
        int last = findlast( nums , target) ; 


        return { first , last } ;
        

    }
};