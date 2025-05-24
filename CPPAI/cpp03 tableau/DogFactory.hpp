#ifndef DOGFACTORY_HPP
#define DOGFACTORY_HPP

#include "ADog.hpp"
#include "IAnimal.hpp"
#include <iostream>

class ADog;

class DogFactory
{
    private:
        ADog* _knownDogs[4];
        int _count;

    public:
        DogFactory();
        DogFactory(const DogFactory& other);
        DogFactory& operator=(const DogFactory& other);
        ~DogFactory();

        void learnDog(ADog* dog); // dog est cloné
        ADog* createDog(const std::string& typeName) const;
};

#endif
