class Solution {
public:

    vector<int> getlmax( vector<int>& height,int & n ){ // function for getting leftmax height

        vector<int> leftmax(n) ;

        leftmax[0] = height[0] ;

        for( int i = 1 ; i < n ; i++){
            leftmax[i] = max(leftmax[i-1] , height[i]) ; // i'th element
        }

        return leftmax ;
    }

    vector<int> getrmax( vector<int>& height,int & n ){// function for getting rightmax height

        vector<int> rightmax(n) ;

        rightmax[n-1] = height[n-1] ;

        for( int i = n-2 ; i >= 0 ; i--){
            rightmax[i] = max(rightmax[i+1] , height[i]) ; // i'th element
        }

        return rightmax ;

    }


    int trap(vector<int>& height) {

        int n = height.size() ; 

        vector<int> lmax = getlmax( height,n );// left
        vector<int> rmax = getrmax( height,n ); // right

        int sum = 0 ; 

        for( int i = 0 ; i < n ; i++){

            int h = min( lmax[i] , rmax[i] ) - height[i]  ;

            sum += h ;  
        }

        return sum ; 
        
    }
};