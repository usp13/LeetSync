class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        for (auto &rseat : reservedSeats) {

            int r = rseat[0];  // row
            int s = rseat[1];  // seat

            mp[r].insert(s);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, bookedseat] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedseat.find(seat) == bookedseat.end();
            };

            bool grpA = isAvailable(2) && isAvailable(3) &&
                        isAvailable(4) && isAvailable(5);

            bool grpB = isAvailable(4) && isAvailable(5) &&
                        isAvailable(6) && isAvailable(7);

            bool grpC = isAvailable(6) && isAvailable(7) &&
                        isAvailable(8) && isAvailable(9);

            if (grpA && grpC) {
                ans += 2;
            }
            else if (grpA || grpB || grpC) {
                ans += 1;
            }
        }

        return ans;
    }
};