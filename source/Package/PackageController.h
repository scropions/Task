//
// Created by Makaveli_Amaru on 06.10.2018.
//


#include "Package.h"
#include <vector>
#include <sstream>
class PackageController {
private:
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    std::vector<std::shared_ptr<Package>> lst;
    std::shared_ptr<Package> findPackage(std::string name);
    std::shared_ptr<Package> findPackage(std::shared_ptr<Package> pckg, std::string tmp_name);

public:
    PackageController()
    {
    }

    void add(std::string name);
    void remove(std::string name);
    void output();
};
