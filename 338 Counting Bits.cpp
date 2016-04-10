class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> binary;
        int step = 0;
        binary.push_back(0);
        for (; (1 << step) <= num; step++) {
            binary.push_back(1 << step);
        }
        binary.push_back(1 << step);

        vector<int> cnt;
        int position = 0;
        int max_binary = 0;
        cnt.push_back(0);
        if (num == 0) return cnt;

        for (int current = 1; current <= num; current++) {
            while (current >= binary[position]) {
                max_binary = binary[position];
                position++;
            }
            cnt.push_back(cnt[current - max_binary] + 1);
        }

        return cnt;
    }
};
