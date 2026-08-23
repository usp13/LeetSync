class Solution {
public:
    bool sumGame(string num) {

        int l = 0 , r = 0 ;
        int lblank = 0 , rblank = 0 ;

        int n = num.size();

        for( int i = 0 ; i < n/2 ; i++){

            if(num[i] != '?')
            l += (num[i] - '0') ;

            else 
            lblank ++ ;

        }


        for( int i = n/2 ; i < n ; i++){

            if(num[i] != '?')
            r += (num[i] - '0') ;

            else 
            rblank ++ ;

        }
        

        if( lblank + rblank == 0)
        return (l != r) ;

        if( (lblank + rblank)%2 == 1)
        return true ;

        
        int mini = min(lblank , rblank ) ;

        lblank -= mini ;
        rblank -= mini ;

        if(lblank >0){

            if(l > r)
            return true ;

            if( 9*(lblank/2) == (r - l))
            return false ;

            else 
            return true ;
        }

        else {

            if(r > l)
            return true ;

            if( 9*(rblank/2) == (l - r))
            return false ;

            else 
            return true ;
        

        }


        return true ;


    }
};