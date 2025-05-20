#include "Bulldog.hpp"

Bulldog::Bulldog(const std::string& name, int age) : ADog(name, age) {}

Bulldog::Bulldog(const Bulldog& other) : ADog(other)
{
    *this = other;
}

Bulldog& Bulldog::operator=(const Bulldog& other)
{
    if (this != &other)
    {
        ADog::operator=(other);
    }
    return (*this);
}

Bulldog::~Bulldog() {}

ADog* Bulldog::clone() const
{
    return (new Bulldog(*this));
}

void Bulldog::makeSound() const
{
    std::cout << this->getName() << ": WOUF WOUF WOUF !!" << std::endl; 
}
