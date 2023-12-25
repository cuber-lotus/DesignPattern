#include <iostream>

class IntelCpu {
public:
    void calculate() {
        std::cout << "IntelCpu " << __func__ << std::endl;
    }
};

class IntelMemory {
public:
    void storage() {
        std::cout << "IntelMemory " << __func__ << std::endl;
    }
};

class Computer {
private:
    IntelCpu intelCpu;
    IntelMemory intelMemory;

public:
    Computer() {
    }
    Computer(IntelCpu intelCpu, IntelMemory intelMemory) {
        this->intelCpu = intelCpu;
        this->intelMemory = intelMemory;
    }

    void startRun() {
        intelCpu.calculate();
        intelMemory.storage();
    }
};

int main() {
    IntelCpu intelCpu;
    IntelMemory intelMemory;
    Computer computer(intelCpu, intelMemory);
    computer.startRun();
}