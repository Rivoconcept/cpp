#include "ADog.hpp"

ADog::ADog(std::string name, int age) : _name(name), _age(age) {}

ADog::~ADog() {}

int ADog::getAge() const
{
    return (this->_age);
}

ADog::ADog(const ADog& other): _name(other._name), _age(other._age) {}

ADog& ADog::operator=(const ADog& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_age = other._age;
    }
    return (*this);
}

const std::string& ADog::getName() const
{
    return (this->_name);
}
