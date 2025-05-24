#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "IAnimal.hpp"

class ADog : public IAnimal
{
    protected:
        std::string _name;
        int _age;

    public:
        ADog(std::string name, int age);
        ADog(const ADog& dog);
        ADog& operator=(const ADog& other);
        virtual ~ADog();

        int getAge() const;
        const std::string& getName() const;

        virtual ADog* clone() const = 0;
};

#endif