#include "House.hpp"

House::House(): _count(0)
{
    for (int i = 0; i < 4; i++)
    {
        _residents[i] = NULL;
    }
}

House::House(const House& other) : _count(other._count)
{
    for (int i=0; i < 4; i++)
    {
        if (other._residents[i])
            _residents[i] = new Human(*other._residents[i]);
        else
            _residents[i] = NULL;
    }
}

House& House::operator=(const House& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _residents[i];
            _residents[i] = NULL;
        }

        _count = other._count;
        for (int i=0; i < 4; i++)
        {
            if (other._residents[i])
                _residents[i] = new Human(*other._residents[i]);
            else
                _residents[i] = NULL;
        }
    }
    return (*this);
}

House::~House()
{
    for (int i = 0; i<4; i++)
    {
        delete _residents[i];
    }
}

void House::addResident(Human* human)
{
    if (_count >= 4)
    {
        std::cout << "House is full!!" << std::endl;
        return;
    }
    if (human)
    {
        _residents[_count++] = new Human(*human);
    }
    else
        std::cout << "Error: trying to add a NULL resident! "<< std::endl;
}

void House::callEveryone() const
{
    for (int i = 0; i < 4; i++)
    {
        if (_residents[i])
        {
            std::cout << this->_residents[i]->getName() << " is walking their dog...\n";
            _residents[i]->walkDog();
        }
    }
}