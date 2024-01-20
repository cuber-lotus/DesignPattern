#include <iostream>
#include <string>

class A {
protected:
    std::string name;
    int         age;

public:
    void methodA() {
        std::cout << "A " << __func__ << std::endl;
    }
};

// 继承转组合
class B {
private:
    // 不用知道a的具体细节
    A a;

public:
    void methodB() {
        std::cout << "B " << __func__ << std::endl;
    }
    // 可以直接转发，也可以添加额外操作
    void methodA() {
        a.methodA();
    }
};

int main() {
    B b;
    b.methodA();
    b.methodB();
}