#ifndef IANIMAL_HPP
#define IANIMAL_HPP

#include <iostream>
#include <string>

class IAnimal
{
    public:
        virtual ~IAnimal() {};

        virtual void makeSound() const = 0;
        virtual IAnimal* clone() const = 0;
};

#endif