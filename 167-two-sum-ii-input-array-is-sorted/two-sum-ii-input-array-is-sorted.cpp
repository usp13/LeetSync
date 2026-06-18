class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

    //Two Pointers  

    int i = 0 ; // first index 
    int j = numbers.size()-1; // last index 

    while ( i < j ) {

        int sum = numbers[i] + numbers[j] ; // sum of two indices !

        if( sum == target){
            return {i + 1 , j + 1};
        }
        else if (sum<target){
            i++ ;
        }
        else{
            j-- ;
        }  
    }

    
    return {-1,-1} ;

        
    }
};