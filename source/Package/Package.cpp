//
// Created by Makaveli_Amaru on 06.10.2018.
//
#include "Package.h"
void Package::add(std::shared_ptr<Package> pckg) {
    nextPackage = pckg;
}
void Package::remove(std::string package_name) {

}
std::string Package::get()
{
    return name;
}
std::shared_ptr<Package> Package::getNext() { return nextPackage;}