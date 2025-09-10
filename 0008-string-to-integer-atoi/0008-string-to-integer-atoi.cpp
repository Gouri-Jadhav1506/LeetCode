class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0; // use long to handle overflow before clamping
        int sign = 1;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Clamp to 32-bit range if overflow
            if (result * sign <= INT_MIN) return INT_MIN;
            if (result * sign >= INT_MAX) return INT_MAX;

            i++;
        }

        return (int)(result * sign);
    }
};
