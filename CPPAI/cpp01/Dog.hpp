#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
class Dog
{
    private:
        std::string _name;
        int _age;

    public:
        Dog(std::string name, int age);
        ~Dog();

        int getAge() const;

        void bark() const;
};

//std::ostream& operator<<(std::ostream& out, const Dog& dog);


#endif