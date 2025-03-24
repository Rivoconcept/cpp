#include "Zombie.hpp"

Zombie::Zombie() : _name("Foo") {}

Zombie::Zombie( std::string name ) : _name(name) {}

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
    Zombie* newZombie = new Zombie(name);
    return (newZombie);
}

void randomChump(std::string name)
{
    Zombie* zombie = new Zombie(name);
    (*zombie).announce();
    delete zombie;
}
