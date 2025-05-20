#ifndef ADOG_H
#define ADOG_H

#include <iostream>
#include <string>

class ADog
{
    private:
        std::string _name;
        int _age;

    public:
        ADog(std::string name, int age);
        ADog(const ADog& ADog);
        ADog& operator=(const ADog& other);
        ~ADog();

        int getAge() const;
        const std::string& getName() const;

        virtual void makeSound() const = 0;
};

//std::ostream& operator<<(std::ostream& out, const ADog& ADog);


#endif