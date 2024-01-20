#include <iostream>
#include <string>

/**
 * base
 */
class NetworkState {
public:
    inline static NetworkState* pNext = nullptr;

    virtual ~NetworkState()  = default;
    virtual void Operation() = 0;
};

class OpenState : public NetworkState {
public:
    static NetworkState* getInstance() {
        static OpenState obj{};
        return &obj;
    }

    void Operation();
};

class CloseState : public NetworkState {
public:
    static NetworkState* getInstance() {
        static CloseState obj{};
        return &obj;
    }

    virtual void Operation();
};

class ConnectState : public NetworkState {
public:
    static NetworkState* getInstance() {
        static ConnectState obj{};
        return &obj;
    }

    virtual void Operation();
};

/**
 * C++的特点
 * 实现与定义分离
 */

/**
 * 具体的实现
 * 这里演示一个循环的状态切换
 */
void OpenState::Operation() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pNext = CloseState::getInstance();
}

void CloseState::Operation() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pNext = ConnectState::getInstance();
}

void ConnectState::Operation() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pNext = OpenState::getInstance();
}

/**
 * main
 * 演示-状态切换
 */
int main() {
    NetworkState::pNext = ConnectState::getInstance();

    for (int i = 0; i < 5; i += 1) {
        NetworkState::pNext->Operation();
    }
}