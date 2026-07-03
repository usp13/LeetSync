class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // MONOTONIC STACK

        //A monotonic stack is a specialized data structure that maintains its elements in either increasing or decreasing order. This property allows it to efficiently solve problems that involve comparisons between elements, often in O(n) time complexity. 

        int n = temperatures.size() ; 

        stack<int> st ; 

        vector<int> ans(n) ;

        for( int i = n-1 ; i >= 0 ; i-- ){

            while( !st.empty() && temperatures[i] >= temperatures[st.top()]){

                st.pop() ; 
            }

            if( st.empty() ){
                ans[i] = 0 ; 
            }
            else {
                ans[i] = st.top() - i ; // No. of days = st.top() - i 
            }

            st.push(i) ; // pushing current index 
        }
        return ans ;
        
    }
};