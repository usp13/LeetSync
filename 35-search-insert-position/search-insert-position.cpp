class Solution {
public:

//     int LOWERBOUND(vector<int>& nums, int n ,int target){

//         int l = 0;
//         int r = n -1;
//         int answer = n ;

//         while (l<=r){
//             int mid = (l + r) /2 ;
//             if(nums[mid]>= target){
//                 answer = min(answer, mid ) ;
//                 r = mid - 1;
//             }
//             else {
//                 l = mid + 1 ;
//             }
//         }
//     return answer ;
//       }

    int searchInsert(vector<int>& nums, int target) {
        // int n = nums.size();

        // int answerLowerbound = LOWERBOUND(nums, n , target);

        // return answerLowerbound ;
    
        // BINARY SEARCH 
        int n = nums.size();
        int l = 0;
        int r = n - 1 ;
        int answer = n;

        for( int i = 0; i<=n -1 ; i++){

            int mid = (l + r) /2 ;
            if( nums[i]==target){
                return i ;
            }

            else if( target <= nums[mid]){
                answer = min(answer , mid) ;
                r = mid - 1;

            }
            else {
                l = mid + 1 ;
            }

        }
        return answer;
        
    }
};