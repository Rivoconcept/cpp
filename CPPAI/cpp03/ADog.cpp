#include "ADog.hpp"

ADog::ADog(std::string name, int age) : _name(name), _age(age) {}

ADog::~ADog() {}

int ADog::getAge() const
{
    return (this->_age);
}

ADog::ADog(const ADog& other)
{
    *this = other;
}

ADog* ADog::clone() const
{
    return (new ADog(*this));
}

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

void ADog::makeSound() const
{
    std::cout << this->_name << ": Default Dog sound..." << std::endl; 
}
