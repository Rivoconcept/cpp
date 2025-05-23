#include "ADog.hpp"
#include "Human.hpp"
#include "House.hpp"
#include "Bulldog.hpp"
#include "Berger.hpp"
#include "IAnimal.hpp"

int main() {
    IAnimal* bulldog = new Bulldog("Rex", 5);
    IAnimal* berger = new Berger("Billy", 6);
    Human* john = new Human("John", 30, dynamic_cast<ADog*>(bulldog));
    Human* lalie = new Human("Lalie", 10, dynamic_cast<ADog*>(berger));

    House house;
    house.addResident(john);
    house.addResident(lalie);

    house.callEveryone();

    delete john;
    delete lalie;
    delete bulldog;
    delete berger;

    return 0;
}

