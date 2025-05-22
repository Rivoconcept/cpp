#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <iostream>
#include <vector>
#include "Human.hpp"

class House
{
    private:
        Human* _residents[4]; // tableau statique
        int _count;           // nombre de résidents actuellement présents

    public:
        House();
        House(const House& other);
        House& operator=(const House& other);
        ~House();

        void addResident(Human* human);
        void callEveryone() const;
};

#endif
