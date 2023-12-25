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

    Equation generateEquation(std::string op) {
        leftNum = generateRandom(0, 100);
        rightNum = generateRandom(0, 100);
        if (op == "+") {
            result = leftNum + rightNum;
        } else if (op == "-") {
            result = leftNum - rightNum;
        }
        this->op = op;
        return *this;
    }
};

int main() {
    srand(time(0));
    Equation equation = Equation().generateEquation("-");
    std::cout << equation.toString() << std::endl;
}
