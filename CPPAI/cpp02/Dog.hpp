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
        Dog(const Dog& dog);
        Dog& operator=(const Dog& other);
        ~Dog();

        int getAge() const;
        const std::string& getName() const;

        void bark() const;
};

//std::ostream& operator<<(std::ostream& out, const Dog& dog);


#endif