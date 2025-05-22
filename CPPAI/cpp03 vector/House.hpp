#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <iostream>
#include <vector>
#include "Human.hpp"

class House
{
    private:
        std::vector<Human*> _residents;

    public:
        House();
        House(const House& other);
        House& operator=(const House& other);
        ~House();

        void addResident(Human* human); // Copie le résident (deep copy)
        void callEveryone() const;      // Fait aboyer tous les chiens
};

#endif
