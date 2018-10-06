//
// Created by Makaveli_Amaru on 06.10.2018.
//

#include "PackageController.h"

std::shared_ptr<Package> PackageController::findPackage(std::string name)
{
    if(lst.size() > 0) {
        std::shared_ptr<Package> tmp_package;
        for(auto it = lst.begin(); it != lst.end(); it++)
        {
            tmp_package = *it;
            while(tmp_package)
            {
                if((*tmp_package).get() == name) return tmp_package;
                else tmp_package = (*tmp_package).getNext();
            }
        }
    }
    return nullptr;
}
std::shared_ptr<Package> PackageController::findPackage(std::shared_ptr<Package> pckg, std::string name)
{
    std::shared_ptr<Package>  tmp_package = pckg;
    while(tmp_package)
    {
        if((*tmp_package).get() == name) return tmp_package;
        else tmp_package = (*tmp_package).getNext();
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
                tmp_pck = findPackage(tmp_pck,splitters[i]);
            }
            if(tmp_pck != nullptr)
            tmp_pck->add(std::make_shared<Package>(splitters[splitters.size() - 1]));
        }
    }
    else
    {
        lst.push_back(std::make_shared<Package>(name));
    }
}
void PackageController::output() {
    if(lst.size() > 0) {
        std::shared_ptr<Package> tmp_package;
        for(auto it = lst.begin(); it != lst.end(); it++)
        {
            tmp_package = *it;
            int counter = 0;
            while(tmp_package)
            {
                for(int i = 0; i < counter; i++)
                    std::cout << "+++";
                std::cout << tmp_package->get() << std::endl;
                tmp_package = (*tmp_package).getNext();
                counter++;
            }
        }
    }
}
void PackageController::remove(std::string name) {
    if(name.find('/') != std::string::npos )
    {
        std::vector<std::string> splitters = split(name,'/');
        std::shared_ptr<Package> tmp_pck = findPackage(splitters[0]);
        if(tmp_pck != nullptr) {
            for (int i = 1; i < splitters.size() - 1; i++) {
                tmp_pck = findPackage(splitters[i]);
                if(tmp_pck != nullptr)
                tmp_pck.reset();
            }
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
