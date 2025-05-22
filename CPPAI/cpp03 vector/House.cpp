#include "House.hpp"

House::House() {}

House::House(const House& other) {
    for (size_t i = 0; i < other._residents.size(); ++i)
        _residents.push_back(new Human(*other._residents[i]));
}

House& House::operator=(const House& other) {
    if (this != &other) {
        // Libérer les anciens résidents
        for (size_t i = 0; i < _residents.size(); ++i)
            delete _residents[i];
        _residents.clear();

        // Copier les nouveaux
        for (size_t i = 0; i < other._residents.size(); ++i)
            _residents.push_back(new Human(*other._residents[i]));
    }
    return *this;
}

House::~House() {
    for (size_t i = 0; i < _residents.size(); ++i)
        delete _residents[i];
}

void House::addResident(Human* human) {
    _residents.push_back(new Human(*human)); // Deep copy
}

void House::callEveryone() const {
    for (size_t i = 0; i < _residents.size(); ++i) {
        std::cout << _residents[i]->getName() << " is walking their dog...\n";
        _residents[i]->walkDog();
    }
}
