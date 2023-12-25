#include <iostream>

class Cup {
public:
    virtual void calculate() = 0;
};

class Memory {
public:
    virtual void storage() = 0;
};

class IntelCpu : public Cup {
public:
    void calculate() override {
        std::cout << "IntelCpu " << __func__ << std::endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage() override {
        std::cout << "IntelMemory " << __func__ << std::endl;
    }
};

class AmdCpu : public Cup {
public:
    void calculate() override {
        std::cout << "AmdCpu " << __func__ << std::endl;
    }
};

class AmdMemory : public Memory {
public:
    void storage() override {
        std::cout << "AmdMemory " << __func__ << std::endl;
    }
};

class Computer {
private:
    Cup* cpu;
    Memory* memory;

public:
    Computer() {
    }
    Computer(Cup* cpu, Memory* memory) {
        this->cpu = cpu;
        this->memory = memory;
    }

    void startRun() {
        cpu->calculate();
        memory->storage();
    }
};

int main() {
    Computer computer;

    IntelCpu intelCpu;
    IntelMemory intelMemory;
    computer = Computer(&intelCpu, &intelMemory);
    computer.startRun();

    AmdCpu amdCpu;
    AmdMemory amdMemory;
    computer = Computer(&amdCpu, &amdMemory);
    computer.startRun();
}