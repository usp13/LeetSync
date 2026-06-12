class Solution {
public:
    
    bool canEat(vector<int>& piles, int h, int speed) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed; // ceil(bananas / speed)

            if (hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {
                high = mid - 1;   // try smaller speed
            }
            else {
                low = mid + 1;    // need larger speed
            }
        }

        return low;
    }
};