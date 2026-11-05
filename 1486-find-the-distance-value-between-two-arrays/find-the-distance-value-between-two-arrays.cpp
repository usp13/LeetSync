class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int count = 0;

        for (int n : arr1) {
            if (isValid(n, arr2, d)) count ++;
        }
        return count;
    }

private:
    bool isValid(int n, vector<int>& arr, int d) {
        
        for (int e : arr) {
            if (abs(e - n) <= d) return false;
        }
        return true;
    }
};