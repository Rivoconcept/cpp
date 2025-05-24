#include "ADog.hpp"
#include "Human.hpp"
#include "House.hpp"
#include "Bulldog.hpp"
#include "Berger.hpp"
#include "IAnimal.hpp"
#include "DogFactory.hpp"


int main() {
    DogFactory factory;

    factory.learnDog(new Bulldog("Bulldog", 4));
    factory.learnDog(new Berger("Berger", 6));

    ADog* dog1 = factory.createDog("Bulldog");
    ADog* dog2 = factory.createDog("Berger");

    Human h1("Alice", 30, dog1);
    Human h2("Bob", 25, dog2);

    House maison;
    maison.addResident(&h1);
    maison.addResident(&h2);

    maison.callEveryone();

    delete dog1;
    delete dog2;

    return 0;
}