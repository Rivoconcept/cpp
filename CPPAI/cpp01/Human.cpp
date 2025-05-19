#include "Human.hpp"


Human::Human(std::string name, int age, Dog dog) : _name(name), _age(age), _dog(dog) {}

Human::~Human() {}

void Human::walkDog() const
{
    std::cout << this->_name << " is walking their dog." << std::endl;
}