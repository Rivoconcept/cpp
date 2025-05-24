#include "Berger.hpp"

Berger::Berger(const std::string& name, int age)
    : ADog(name, age) {}

Berger::Berger(const Berger& other) : ADog(other) {}

Berger& Berger::operator=(const Berger& other)
{
    if (this != &other)
    {
        ADog::operator=(other);
    }
    return (*this);
}

Berger::~Berger() {}

void Berger::makeSound() const
{
    std::cout << this->_name << " dit : WOW WOW WOW 🐶" << std::endl;
}

ADog* Berger::clone() const
{
    return new Berger(*this);
}
