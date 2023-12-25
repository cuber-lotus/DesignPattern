#include <iostream>

class Bird {
protected:
    double runSpeed;
    double flySpeed;

public:
    virtual void setRunSpeed(double runSpeed) {
        this->runSpeed = runSpeed;
    }

    virtual void setFlySpeed(double flySpeed) {
        this->flySpeed = flySpeed;
    }

    double calcFlyTime(double distance) {
        return distance / flySpeed;
    }

    double calcRunTime(double distance) {
        return distance / runSpeed;
    }
};

class Parrot : public Bird {
public:
    void studySpeak() {
        std::cout << __func__ << std::endl;
    }
};

class Ostrich : public Bird {
public:
    virtual void setFlySpeed(double flySpeed) override {
        this->flySpeed = 0;
    }
};

int main() {
    Bird* parrot = new Parrot();
    parrot->setFlySpeed(150.0);
    std::cout << "fly 300km" << std::endl;
    std::cout << "parrot uses " << parrot->calcFlyTime(300.0) << " hours"
              << std::endl;

    Bird* ostrich = new Ostrich();
    ostrich->setFlySpeed(150.0);
    std::cout << "fly 300km" << std::endl;
    std::cout << "ostrich uses " << ostrich->calcFlyTime(300.0) << " hours"
              << std::endl;
}
