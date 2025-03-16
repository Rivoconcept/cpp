#include "Zombie.hpp"

Zombie::Zombie() : _name("Foo") {}

Zombie::~Zombie()
{
    std::cout << getName() << " has been destroyed." << std::endl;
}

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie* newZombie = new Zombie();
    newZombie->setName(name);
    return (newZombie);
}

void randomChump(std::string name)
{
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
