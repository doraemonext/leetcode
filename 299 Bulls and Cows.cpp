class Solution {
public:
    string getHint(string secret, string guess) {
        int Acount = 0;
        int Bsecret[128] = { 0 };
        int Bguess[128] = { 0 };
        for (int i = 0; i < (int)secret.size(); i++) {
            if (secret[i] == guess[i]) {
                Acount++;
            } else {
                Bsecret[secret[i]]++;
                Bguess[guess[i]]++;
            }
        }

        int Bcount = 0;
        for (int i = 0; i < 128; i++) {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
                if (Bsecret[i] > 0 && Bguess[i] > 0) {
                    Bcount += min(Bsecret[i], Bguess[i]);
                }
            }
        }

        return to_string(Acount) + "A" + to_string(Bcount) + "B";
    }
};
