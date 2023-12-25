#include <iostream>

// 接口过于庞大
class PhoneFunction {
public:
    virtual void call() = 0;
    virtual void message() = 0;
    virtual void camera() = 0;
};

class ApplePhone : public PhoneFunction {
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

class OldPhone : public PhoneFunction {
public:
    virtual void call() override {
        std::cout << "Old " << __func__ << std::endl;
    }
    virtual void message() override {
        std::cout << "Old " << __func__ << std::endl;
    }
    virtual void camera() override {
        std::cout << "Old " << __func__ << std::endl;
    }
};
