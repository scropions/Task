#include <iostream>
#include <c++/algorithm>
#include "Package/PackageController.h"
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
int main() {
    std::shared_ptr<PackageController> packageController = std::make_shared<PackageController>();
    while(true)
    {
        std::string command = "";
        std::getline(std::cin, command);
        std::vector<std::string> vec = split(command,' ');
        command.replace(0,command.find(" ")+1,"");
        std::replace(command.begin(),command.end(), ' ','/');
        if(vec[0] == "add" || vec[0] == "create") packageController->add(command);
        if(vec[0] == "print") packageController->output();
        if(vec[0] == "remove") packageController->remove(command);
        if(command == "quit") break;
    }

    return 0;
}