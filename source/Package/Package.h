//
// Created by Makaveli_Amaru on 06.10.2018.
//

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <memory>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/split_member.hpp>
class Package
{
private:

    /*================================
     *============Function============
     * ===============================
     */
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const
    {
        ar & name;
        ar & nextPackage;
    }

    template<class Archive>
    void load(Archive & ar, const unsigned int version)
    {
        ar & name;
        ar & nextPackage;
    }

    BOOST_SERIALIZATION_SPLIT_MEMBER()
    /*================================
     *============Variable============
     * ===============================
     */
    std::string name;
    std::vector<std::shared_ptr<Package>> nextPackage;
    friend class boost::serialization::access;
public:
    Package()
    = default;

    explicit Package(std::string name)
    {
        this->name = std::move(name);
    }
    void add(std::shared_ptr<Package> pckg);
    std::vector<std::shared_ptr<Package>> getNext();
    std::string get();
    void remove(std::string package_name);
};
