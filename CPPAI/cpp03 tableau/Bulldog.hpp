#ifndef BULLDOG_HPP
#define BULLDOG_HPP

#include <iostream>
#include <string>
#include "IAnimal.hpp"
#include "ADog.hpp"


class Bulldog : public ADog
{
    public:
        Bulldog(const std::string& name, int age);
        Bulldog(const Bulldog& other);
        Bulldog& operator=(const Bulldog& other);
        ~Bulldog();

        void makeSound() const;
        ADog* clone() const;
};

#endif