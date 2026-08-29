class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> vec = nums;
        
        sort(vec.begin(), vec.end());

        int grpnum = 0;

        unordered_map<int, int> mp; // Number -> Group
        unordered_map<int, list<int>> gp; // Group -> sorted numbers

        mp[vec[0]] = grpnum;

        gp[grpnum].push_back(vec[0]);

        for (int i = 1; i < n; i++) {

            if (vec[i] - vec[i - 1] > limit) {
                grpnum++;
            }

            mp[vec[i]] = grpnum;

            gp[grpnum].push_back(vec[i]);
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            int group = mp[num];

            ans[i] = gp[group].front();

            gp[group].pop_front();
        }

        return ans;
    }
};