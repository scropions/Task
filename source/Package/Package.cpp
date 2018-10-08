//
// Created by Makaveli_Amaru on 06.10.2018.
//
#include "Package.h"
void Package::add(std::shared_ptr<Package> pckg) {
    nextPackage.push_back(pckg);
}
void Package::remove(std::string package_name) {
    for(int i = 0; i < nextPackage.size(); i++)
    {
        if((*nextPackage[i]).get() == package_name) nextPackage.erase(nextPackage.begin()+i);
    }

}
std::string Package::get()
{
    return name;
}
std::vector<std::shared_ptr<Package>> Package::getNext() { return nextPackage; }