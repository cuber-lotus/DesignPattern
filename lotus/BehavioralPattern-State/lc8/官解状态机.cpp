// https://leetcode.cn/problems/string-to-integer-atoi/submissions/495474757/
class Solution {
private:
    enum State {
        State_Start,
        State_Sign,
        State_Digit,
        State_End
    };
    vector<vector<State>> table;

public:
    Solution() {
        table.resize(State_End + 1);
        table[State_Start] = {State_Start, State_Sign, State_Digit, State_End};
        table[State_Sign]  = {State_End,   State_End,  State_Digit, State_End};
        table[State_Digit] = {State_End,   State_End,  State_Digit, State_End};
        table[State_End]   = {State_End,   State_End,  State_End,   State_End};
    }

    State getState(char ch) {
        if (isspace(ch)) {
            return State_Start;
        }
        if (ch == '+' || ch == '-') {
            return State_Sign;
        }
        if (isdigit(ch)) {
            return State_Digit;
        }
        return State_End;
    }

public:
    // 默认符号为正号，(1:+) (-1:-)
    int sign = 1;
    long long ans = 0;
    
    State next(State state, char ch) {
        // 基于当前状态和当前字符共同决定
        state = table[state][getState(ch)];
        switch (state) {
        case State_Start : {
            // pass 等待开始
        } break;
        case State_Sign : {
            sign = (ch == '+') ? 1 : -1;
        } break;
        case State_Digit : {
            ans = ans * 10 + (ch - '0');
            // 根据符号处理，对溢出进行收缩
            if (sign == 1) {
                ans = min(ans, 1LL * INT_MAX);
            } else {
                ans = min(ans, -1LL * INT_MIN);
            }
        } break;
        case State_End : {
            // pass 等待结束
        } break;
        }
        return state;
    }

public:
    int myAtoi(string s) {
        State state = State_Start;
        for (char ch : s) {
            state = next(state, ch);
        }
        return ans * sign;
    }
};