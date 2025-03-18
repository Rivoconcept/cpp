/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:39 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/18 17:03:57 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

const std::string& HumanB::getName() const
{
    return (this->_name);
}

void HumanB::setName(std::string name)
{
    this->_name = name;
}

const std::string& HumanB::getWeapon() const
{
    return (this->_weapon->getType());
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack() const
{
    if (this->_weapon)
        std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
    else
        std::cout << getName() << " has no weapon" << std::endl;
}

