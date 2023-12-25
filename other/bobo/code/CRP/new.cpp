#include <iostream>
#include <string>

class A {
protected:
    std::string name;
    int age;

public:
    void methodA() {
        std::cout << "A " << __func__ << std::endl;
    }
};

class B {
private:
    A a;

public:
    void methodB() {
        std::cout << "B " << __func__ << std::endl;
    }

    void methodA() {
        a.methodA();
    }
};

int main() {
    B b;
    b.methodA();
    b.methodB();
}