#include "Zombie.hpp"

int main (void)
{
    Zombie stackZombie;
    stackZombie.announce();
    std::cout << std::endl;
    std::cout << "Creating a zombie on the heap..." << std::endl;
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << std::endl;
    std::cout << "Creating a zombie on the stack..." << std::endl;
    randomChump("StackZombie");
    delete heapZombie;
    return (0);
}

