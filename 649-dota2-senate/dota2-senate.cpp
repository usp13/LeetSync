class Solution {
public:
    bool remove(string &senate, char ch, int idx) {
        bool removeLeft = false;
        int start = idx;
        int m = senate.length();

        while (true) {
            if (idx == 0)
                removeLeft = true;

            if (senate[idx] == ch) {
                senate.erase(senate.begin() + idx);
                break;
            }

            idx = (idx + 1) % senate.length();

            // searched whole circle
            if (idx == start)
                return false;
        }

        return removeLeft;
    }

    string predictPartyVictory(string senate) {

        int rcount = count(senate.begin(), senate.end(), 'R');
        int dcount = senate.size() - rcount;

        int idx = 0;

        while (rcount > 0 && dcount > 0) {

            idx %= senate.size();

            if (senate[idx] == 'R') {

                bool removeLeft = remove(senate, 'D', (idx + 1) % senate.size());
                dcount--;

                if (removeLeft)
                    idx--;
            }
            else {

                bool removeLeft = remove(senate, 'R', (idx + 1) % senate.size());
                rcount--;

                if (removeLeft)
                    idx--;
            }

            if (!senate.empty())
                idx = (idx + 1 + senate.size()) % senate.size();
        }

        return rcount == 0 ? "Dire" : "Radiant";
    }
};