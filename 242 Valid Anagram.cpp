class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int cntS[26] = { 0 };
        int cntT[26] = { 0 };
        for (int i = 0; i < (int)s.size(); i++) {
            cntS[s[i]-'a']++;
            cntT[t[i]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (cntS[i] != cntT[i]) {
                return false;
            }
        }
        return true;
    }
};
