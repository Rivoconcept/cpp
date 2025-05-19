#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <iostream>
#include <string>

#include "Dog.hpp"

class Human
{
    private:
        std::string _name;
        int _age;
        Dog _dog;
    
    public:
        Human(std::string name, int age, Dog dog);
        ~Human();

        void walkDog() const;
};

#endif