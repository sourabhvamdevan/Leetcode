
class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int sign = 1;
        long res = 0;

        while (idx < s.length() && s[idx] == ' ') {
            idx++;
        }

        if (idx < s.length() && (s[idx] == '-' || s[idx] == '+')) {
            sign = (s[idx] == '-') ? -1 : 1;
            idx++;
        }

        while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
            res = res * 10 + (s[idx] - '0');

            if (res * sign >= INT_MAX) return INT_MAX;
            if (res * sign <= INT_MIN) return INT_MIN;

            idx++;
        }

        return (int)(res * sign);
    }
};