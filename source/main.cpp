#include "Package/PackageController.h"
#include <iostream>
#include <c++/algorithm>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
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
void save(const std::shared_ptr<PackageController> &pckg)
{
    std::ofstream ofs("save.dat");
    if(ofs) {
        boost::archive::text_oarchive ar(ofs);
        ar & pckg;
    }
    ofs.close();
}
int main() {
    std::shared_ptr<PackageController> packageController;
    std::ifstream ifs( "save.dat" );
    if(ifs){ boost::archive::text_iarchive ar( ifs ); ar & packageController; std::cout << "Data loaded" << std::endl;} else { packageController = std::make_shared<PackageController>(); } //load
    ifs.close();
    while(true)
    {
        std::string command;
        std::getline(std::cin, command);
        std::vector<std::string> vec = split(command,' ');
        command.replace(0,command.find(' ')+1,"");
        std::replace(command.begin(),command.end(), ' ','/');

        if(vec[0] == "add" || vec[0] == "create")  { packageController->add(command); save(packageController); }
        if(vec[0] == "print") packageController->output(command);
        if(vec[0] == "remove") { packageController->remove(command); save(packageController); }
        if(command == "quit") break;
    }

    return 0;
}