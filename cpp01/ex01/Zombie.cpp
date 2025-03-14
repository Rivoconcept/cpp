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

int main (void)
{
    Zombie stackZombie;
    stackZombie.announce();
    std::cout << "Creating a zombie on the heap..." << std::endl;
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << std::endl;
    std::cout << "Creating a zombie on the stack..." << std::endl;
    randomChump("StackZombie");
    delete heapZombie;
    return (0);
}

