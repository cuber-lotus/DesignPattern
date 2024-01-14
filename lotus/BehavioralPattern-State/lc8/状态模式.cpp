// https://leetcode.cn/problems/string-to-integer-atoi/submissions/495519218/
// 状态模式的基类
class StateBase {
public:
    // 默认符号为正号，(1:+) (-1:-)
    inline static int       sign = 1;
    inline static long long ans  = 0;

    static void init() {
        sign = 1;
        ans  = 0;
    }

public:
    ~StateBase() = default;

    virtual StateBase* nextState(char ch) = 0;
    // 若有操作，在具体重载
    virtual void handle(char ch) {
    }
};

// 每个状态的class
class StateStart : public StateBase {
public:
    static StateBase* getInstance() {
        static StateStart obj{};
        return &obj;
    }

    StateBase* nextState(char ch) override;
};

class StateSign : public StateBase {
public:
    static StateBase* getInstance() {
        static StateSign obj{};
        return &obj;
    }

    StateBase* nextState(char ch) override;
    void       handle(char ch) override {
        sign = (ch == '+') ? 1 : -1;
    }
};

class StateDigit : public StateBase {
public:
    static StateBase* getInstance() {
        static StateDigit obj{};
        return &obj;
    }

    StateBase* nextState(char ch) override;
    void       handle(char ch) override {
        ans = ans * 10 + (ch - '0');
        // 根据符号处理，对溢出进行收缩
        if (sign == 1) {
            ans = min(ans, 1LL * INT_MAX);
        } else {
            ans = min(ans, -1LL * INT_MIN);
        }
    }
};

class StateEnd : public StateBase {
public:
    static StateBase* getInstance() {
        static StateEnd obj{};
        return &obj;
    }

    StateBase* nextState(char ch) override;
};

//! 状态的转移
// 起始状态后，后续都有可能
StateBase* StateStart::nextState(char ch) {
    if (isspace(ch)) {
        return StateStart::getInstance();
    }
    if (ch == '+' || ch == '-') {
        return StateSign::getInstance();
    }
    if (isdigit(ch)) {
        return StateDigit::getInstance();
    }
    return StateEnd::getInstance();
}

// 符号状态后只能是数字，否则end
StateBase* StateSign::nextState(char ch) {
    if (isdigit(ch)) {
        return StateDigit::getInstance();
    }
    return StateEnd::getInstance();
}

// 数字状态后只能是数字，否则end
StateBase* StateDigit::nextState(char ch) {
    if (isdigit(ch)) {
        return StateDigit::getInstance();
    }
    return StateEnd::getInstance();
}

// end后永远是end
StateBase* StateEnd::nextState(char ch) {
    return StateEnd::getInstance();
}

class Solution {
public:
    int myAtoi(string s) {
        StateBase::init();
        StateBase* state_ptr = StateStart::getInstance();
        for (char ch : s) {
            state_ptr = state_ptr->nextState(ch);
            state_ptr->handle(ch);
        }
        return StateBase::ans * StateBase::sign;
    }
};