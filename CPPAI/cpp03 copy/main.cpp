#include "Dog.hpp"
#include "Human.hpp"
#include "House.hpp"

int main()
{
    Dog* original = new Dog("Billy", 5);
    Human h("Tom", 30, original);
    House house(h, *original);

    house.dailyLife();

    delete original;  // Doit pouvoir être supprimé sans casser l’objet `h`

 

    return 0;
}
