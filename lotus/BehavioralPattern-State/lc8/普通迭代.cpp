// https://leetcode.cn/problems/string-to-integer-atoi/submissions/495462208/
class Solution {
public:
    int myAtoi(string s) {
        const int n = s.size();
        int i = 0;
        
        // 略过空格
        while (i < n && s[i] == ' ') {
            i += 1;
        }

        int sign = 1;
        // 处理符号
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i += 1;
        }

        int ans = 0;
        // 遍历，获取答案
        for (; i < n; i += 1) {
            // 遇到首个非数字字符，则终止
            if (! isdigit(s[i])) {
                break;
            }
            int digit = s[i] - '0';
            // 要到最值了
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit;
        }

        return ans * sign;
    }
};
