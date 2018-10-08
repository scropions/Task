//
// Created by Makaveli_Amaru on 06.10.2018.
//

#include "PackageController.h"
std::shared_ptr<Package> PackageController::findPackage(std::string name)
{
    if(!lst.empty()) {
        std::shared_ptr<Package> tmp_package;
        for (auto &it : lst) {
            tmp_package = it;
            if ((*tmp_package).get() == name) return tmp_package;
        }
    }
    return nullptr;
}
std::shared_ptr<Package> PackageController::findPackage(std::vector<std::shared_ptr<Package>> pckg, std::string name)
{
    std::shared_ptr<Package> tmp_package;
    for (auto &it : pckg) {
        tmp_package = it;
        if (it->get() == name) return it;
    }
    return nullptr;
}
void PackageController::add(std::string name) {
    if(name.find('/') != std::string::npos )
    {
        std::vector<std::string> splitters = split(name,'/');
        std::shared_ptr<Package> tmp_pck = findPackage(splitters[0]);
        if(tmp_pck != nullptr) {
            for (int i = 1; i < splitters.size() - 1; i++) {
                tmp_pck = findPackage(tmp_pck->getNext(),splitters[i]);
            }
            if(tmp_pck != nullptr)
            tmp_pck->add(std::make_shared<Package>(splitters[splitters.size() - 1]));
        }
        else
        {
            std::cout << "Package not found" << std::endl;
            return;
        }
    }
    else
    {
        lst.push_back(std::make_shared<Package>(name));
    }
}
void PackageController::output(std::string name) {
    if(!lst.empty()) {
        for (auto &it : lst) {
            if(it->get() == name)
            if(!it->getNext().empty())
            {
                std::cout << it->get() << std::endl;
                output(it->getNext());
            }
            else
            {
                std::cout << it->get() << std::endl;
            }
        }
    }
}
void PackageController::output(std::vector<std::shared_ptr<Package>> packages){
    for (auto &package : packages) {
        if(!package->getNext().empty())
        {
            std::cout << package->get() << std::endl;
            output(package->getNext());
        }
        else
        {
            std::cout << package->get() << std::endl;
        }
    }
}
void PackageController::remove(std::string name) {
    if(name.find('/') != std::string::npos )
    {
        std::vector<std::string> splitters = split(name,'/');
        std::shared_ptr<Package> tmp_pck = findPackage(splitters[0]);
        if(tmp_pck != nullptr) {
            for (int i = 1; i < splitters.size()-1; i++) {
                tmp_pck = findPackage(tmp_pck->getNext(),splitters[i]);
            }
            if(tmp_pck) {
                tmp_pck->remove(splitters[splitters.size()-1]);
            } else std::cout << "Package not found" << std::endl;
        }
    }
    else
    {
        for(int i = 0; i < lst.size(); i++)
        {
            if((*lst[i]).get() == name) lst.erase(lst.begin() + i);
        }
    }
}
