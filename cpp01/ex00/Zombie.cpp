/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:39:01 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/03/13 19:02:49 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    delete heapZombie;
    std::cout << "\nCreating a zombie on the stack..." << std::endl;
    randomChump("StackZombie");

    return (0);
}

