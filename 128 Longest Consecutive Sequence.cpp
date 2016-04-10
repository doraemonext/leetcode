class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (auto i : nums) {
            used[i] = false;
        }

        int longest = 0;
        for (auto i : nums) {
            if (used[i]) {
                continue;
            }

            int length = 1;
            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                length++;
            }
            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                length++;
            }
            longest = max(length, longest);
        }

        return longest;
    }
};
