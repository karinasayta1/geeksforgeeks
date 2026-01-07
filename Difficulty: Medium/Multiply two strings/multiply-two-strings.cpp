class Solution {
public:
    string multiplyStrings(string &s1, string &s2) {

        bool neg = false;

        if (s1[0] == '-') {
            neg = !neg;
            s1 = s1.substr(1);
        }

        if (s2[0] == '-') {
            neg = !neg;
            s2 = s2.substr(1);
        }

        int l1 = s1.size(), l2 = s2.size();
        vector<int> result(l1 + l2, 0);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                result[i + j] += (s1[i] - '0') * (s2[j] - '0');
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }

        string ans = "";
        bool leadingZero = true;

        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] != 0) leadingZero = false;
            if (!leadingZero)
                ans += char(result[i] + '0');
        }

        if (ans.empty()) return "0";
        if (neg) ans = "-" + ans;

        return ans;
    }
};
