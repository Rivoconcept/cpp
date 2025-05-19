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
        Dog* _dog;
    
    public:
        Human(std::string name, int age, Dog* dog);
        Human(const Human& other);
        Human& operator=(const Human& other);
        ~Human();

        const std::string& getName() const;

        void walkDog() const;
};

#endif