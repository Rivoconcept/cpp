#include "Human.hpp"

Human::Human(std::string name, int age, const ADog* dog) : _name(name), _age(age), _dog(dog->clone()) {}

Human::Human(const Human& other): _dog(NULL)
{
    *this = other;
}

Human& Human::operator=(const Human& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_age = other._age;
        delete this->_dog;
        this->_dog = other._dog->clone();
    }
    return (*this);
}

const std::string& Human::getName() const
{
    return (this->_name);
}

Human::~Human()
{
    delete this->_dog;
}

void Human::walkDog() const
{
    this->_dog->makeSound();
}

