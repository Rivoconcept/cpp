#ifndef BULLDOG_H
#define BULLDOG_H

#include <iostream>
#include <string>
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