#include "Human.hpp"

Human::Human(std::string name, int age, Dog* dog) : _name(name), _age(age), _dog(new Dog(*dog)) {}

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
        if (this->_dog)
            delete this->_dog;
        
        this->_dog = new Dog(*other._dog);
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
    this->_dog->bark();
}

