#include <iostream>

class Animal {
protected:
    double runSpeed;

public:
    virtual void setRunSpeed(double runSpeed) {
        this->runSpeed = runSpeed;
    }

    double calcRunTime(double distance) {
        return distance / runSpeed;
    }
};

class Bird : public Animal {
protected:
    double flySpeed;

public:
    virtual void setFlySpeed(double flySpeed) {
        this->flySpeed = flySpeed;
    }

    double calcFlyTime(double distance) {
        return distance / flySpeed;
    }
};

class Parrot : public Bird {
public:
    void studySpeak() {
        std::cout << __func__ << std::endl;
    }
};

class Ostrich : public Animal {};

int main() {
    Animal* ostrich = new Ostrich();
    ostrich->setRunSpeed(150.0);
    std::cout << "run 300km" << std::endl;
    std::cout << "ostrich uses " << ostrich->calcRunTime(300.0) << " hours"
              << std::endl;
}
