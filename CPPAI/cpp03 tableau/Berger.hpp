#ifndef BERGER_H
#define BERGER_H

#include <iostream>
#include <string>
#include "IAnimal.hpp"
#include "ADog.hpp"

class Berger : public ADog
{
    public:
        Berger(const std::string& name, int age);
        Berger(const Berger& other);
        Berger& operator=(const Berger& other);
        ~Berger();

        void makeSound() const;
        ADog* clone() const;
};

#endif