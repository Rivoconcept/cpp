/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:59:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:16:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
