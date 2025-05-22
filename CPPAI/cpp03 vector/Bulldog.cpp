#include "Bulldog.hpp"

Bulldog::Bulldog(const std::string& name, int age) : ADog(name, age) {}

Bulldog::Bulldog(const Bulldog& other) : ADog(other) {}

Bulldog& Bulldog::operator=(const Bulldog& other)
{
    if (this != &other)
        ADog::operator=(other); // Copie _name et _age
    return *this;
}

Bulldog::~Bulldog() {}

void Bulldog::makeSound() const
{
    std::cout << this->_name << " dit : WOUF WOUF WOUF 🐶" << std::endl;
}

IAnimal* Bulldog::clone() const
{
    return new Bulldog(*this);
}
