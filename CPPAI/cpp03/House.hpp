#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
#include "Human.hpp"
#include "Dog.hpp"

class Human;
class Dog;

class House
{
    private:
        Human* _human;
        Dog*    _dog;
    public:
        House();
        House(const Human& h, const Dog& d);
        ~House();

        void dailyLife() const;
};

#endif