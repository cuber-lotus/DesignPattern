#include <iostream>
#include <string>

class UserInfo {
private:
    long userID;
    std::string userName;
    std::string phone;
    std::string province;
    std::string city;
    std::string region;
    std::string detailAddress;

public:
    void save() {
        std::cout << "save user information" << std::endl;
    }

    void saveAddress() {
        std::cout << "save address information" << std::endl;
    }
};