#include "Dog.hpp"

Dog::Dog(std::string name, int age) : _name(name), _age(age) {}

Dog::~Dog() {}

int Dog::getAge() const
{
    return (this->_age);
}

Dog::Dog(const Dog& other)
{
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_age = other._age;
    }
    return (*this);
}

const std::string& Dog::getName() const
{
    return (this->_name);
}

void Dog::bark() const
{
    std::cout << this->_name << ": WOUF WOUF WOUF !!" << std::endl; 
}
