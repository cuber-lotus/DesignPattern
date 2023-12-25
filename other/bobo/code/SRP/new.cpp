#include <iostream>
#include <list>
#include <string>

class Address {
private:
    std::string city;
    std::string region;
    std::string detailAddress;

public:
    void saveAddress() {
        std::cout << "save address information" << std::endl;
    }
};

class UserInfo {
private:
    long userID;
    std::string userName;
    std::string phone;
    std::string province;
    std::list<Address> addressList;

public:
    void save() {
        std::cout << "save user information" << std::endl;
    }
};