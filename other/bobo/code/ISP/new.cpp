#include <iostream>

// 接口粒度最小
struct Call {
    virtual void call() = 0;
};

struct Message {
    virtual void message() = 0;
};

struct Camera {
    virtual void camera() = 0;
};

class ApplePhone : public Call, public Message, public Camera {
public:
    virtual void call() override {
        std::cout << "Apple " << __func__ << std::endl;
    }
    virtual void message() override {
        std::cout << "Apple " << __func__ << std::endl;
    }
    virtual void camera() override {
        std::cout << "Apple " << __func__ << std::endl;
    }
};

class OldPhone : public Call, public Message {
public:
    virtual void call() override {
        std::cout << "Old " << __func__ << std::endl;
    }
    virtual void message() override {
        std::cout << "Old " << __func__ << std::endl;
    }
};
