#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    std::string license_plate;
    std::string owner_name;

public:
    Vehicle() : license_plate(""), owner_name("") {}

    void setDetails(const std::string &plate, const std::string &owner)
    {
        license_plate = plate;
        owner_name = owner;
    }

    const std::string &getLicensePlate() const
    {
        return license_plate;
    }

    const std::string &getOwnerName() const
    {
        return owner_name;
    }
    void displayDetails() const
    {
        std::cout << "License Plate: " << getLicensePlate() << std::endl;
        std::cout << "Owner: " << getOwnerName() << std::endl;
    }
};
