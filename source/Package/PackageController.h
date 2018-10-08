//
// Created by Makaveli_Amaru on 06.10.2018.
//


#include "Package.h"
#include <sstream>
#include <fstream>
class PackageController {
private:
    /*================================
     *============Function============
     * ===============================
     */
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const
    {
        ar & lst;
    }

    template<class Archive>
    void load(Archive & ar, const unsigned int version)
    {
        ar & lst;
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()
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
    /*================================
     *============Variable============
     * ===============================
     */
    std::vector<std::shared_ptr<Package>> lst;
    std::shared_ptr<Package> findPackage(std::string name);
    std::shared_ptr<Package> findPackage(std::vector<std::shared_ptr<Package>> pckg, std::string tmp_name);
    friend class boost::serialization::access;

public:
    PackageController()
    = default;

    void add(std::string name);
    void remove(std::string name);
    void output(std::string name);
    void output(std::vector<std::shared_ptr<Package>> packages);
};
