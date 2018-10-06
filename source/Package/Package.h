//
// Created by Makaveli_Amaru on 06.10.2018.
//

#include <string>
#include <vector>
#include <iostream>
#include <memory>
class Package
{
private:
    std::string name;
    std::shared_ptr<Package> nextPackage;
public:

    Package(std::string name)
    {
        this->name = name;
    }
    void add(std::shared_ptr<Package> pckg);
    std::shared_ptr<Package> getNext();
    std::string get();
    void remove(std::string package_name);
};
