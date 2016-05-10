class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> tnums(len + 2, 1);
        vector<vector<int>> f(len + 2, vector<int>(len + 2, 0));

        for (int i = 0; i < (int)nums.size(); i++) {
            tnums[i+1] = nums[i];
        }

        return search(tnums, f, 1, len);
    }

    int search(vector<int>& tnums, vector<vector<int>>& f, int left, int right) {
        if (f[left][right]) return f[left][right];

        int max_coins = 0;
        for (int x = left; x <= right; x++) {
            int lcoins = search(tnums, f, left, x - 1);
            int rcoins = search(tnums, f, x + 1, right);
            max_coins = max(max_coins, lcoins + rcoins + tnums[left-1] * tnums[x] * tnums[right+1]);
        }
        return f[left][right] = max_coins;
    }
};
