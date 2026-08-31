class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> st;

        while (true) {

            int sum = 0;

            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            if (sum == 1) {
                return true;
            }

            // If we've already seen this number, we're in a cycle
            if (st.find(sum) != st.end()) {
                return false;
            }

            st.insert(sum);
            n = sum;
        }
    }
};