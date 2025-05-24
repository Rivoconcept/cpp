#include "DogFactory.hpp"
#include <iostream>

DogFactory::DogFactory() : _count(0) {
    for (int i = 0; i < 4; ++i)
        _knownDogs[i] = NULL;
}

DogFactory::DogFactory(const DogFactory& other) : _count(0) {
    for (int i = 0; i < 4; ++i)
        _knownDogs[i] = other._knownDogs[i] ? other._knownDogs[i]->clone() : NULL;
    _count = other._count;
}

DogFactory& DogFactory::operator=(const DogFactory& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _knownDogs[i];
            _knownDogs[i] = other._knownDogs[i] ? other._knownDogs[i]->clone() : NULL;
        }
        _count = other._count;
    }
    return *this;
}

DogFactory::~DogFactory()
{
    for (int i = 0; i < 4; ++i)
        delete _knownDogs[i];
}

void DogFactory::learnDog(ADog* dog) {
    if (!dog || _count >= 4)
        return;
    // On clone pour éviter les effets de bord
    _knownDogs[_count++] = dog->clone();
    delete dog;
}

ADog* DogFactory::createDog(const std::string& typeName) const {
    for (int i = 0; i < _count; ++i) {
        if (_knownDogs[i]->getName() == typeName)
            return _knownDogs[i]->clone();
    }
    std::cout << "Dog type \"" << typeName << "\" not found.\n";
    return NULL;
}
