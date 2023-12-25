#include <ctime>
#include <iostream>
#include <string>

class Equation {
protected:
    int leftNum;
    int rightNum;
    int result;
    std::string op;

public:
    std::string toString() {
        return std::to_string(leftNum) + op + std::to_string(rightNum) + "=" +
               std::to_string(result);
    }

    int generateRandom(int min, int max) {
        return rand() % (max - min + 1) + min;
    }

    // 抽象方法
    // 注意，C++中，抽象基类无法实例化，因此无法直接返回`Equation`
    virtual Equation* generateEquation() = 0;
};

class AddEquation : public Equation {
public:
    Equation* generateEquation() override {
        leftNum = generateRandom(0, 100);
        rightNum = generateRandom(0, 100);
        result = leftNum + rightNum;
        this->op = "+";
        return this;
    }
};

class SubEquation : public Equation {
public:
    Equation* generateEquation() override {
        leftNum = generateRandom(0, 100);
        rightNum = generateRandom(0, 100);
        result = leftNum - rightNum;
        this->op = "-";
        return this;
    }
};

int main() {
    srand(time(0));
    // 多态
    Equation* equation = (new SubEquation())->generateEquation();
    std::cout << equation->toString() << std::endl;
    delete equation;

    equation = (new AddEquation())->generateEquation();
    std::cout << equation->toString() << std::endl;
    delete equation;
}
