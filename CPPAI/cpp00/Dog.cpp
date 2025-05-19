#include "Dog.hpp"

Dog::Dog(std::string name, int age) : _name(name), _age(age) {}

Dog::~Dog() {}

int Dog::getAge() const
{
    return (this->_age);
}

void Dog::bark() const
{
    std::cout << this->_name << ": WOUF WOUF WOUF !!" << std::endl; 
}
