#include "ADog.hpp"
#include "Human.hpp"
#include "House.hpp"
#include "Bulldog.hpp"
#include "IAnimal.hpp"

int main() {
    IAnimal* dog1 = new Bulldog("Rex", 5);
    Human* john = new Human("John", 30, dynamic_cast<ADog*>(dog1));

    House house;
    house.addResident(john);

    house.callEveryone();

    delete john;
    delete dog1;

    return 0;
}

