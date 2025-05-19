
#include "House.hpp"

House::House() {}

House::House(const Human& h, const Dog& d): _human(new Human(h)), _dog(new Dog(d)) {}


void House::dailyLife() const
{
    std::cout << this->_dog->getName() << ": WOUF WOUF !!" << std::endl;
    std::cout << this->_human->getName() << " is walking their dog" << std::endl;
}

House::~House()
{
    delete this->_human;
    delete this->_dog;
}