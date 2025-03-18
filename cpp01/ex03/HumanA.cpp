/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:21 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/18 17:00:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

const std::string& HumanA::getName() const
{
    return (this->_name);
}

void HumanA::setName(std::string name)
{
    this->_name = name;
}

const std::string& HumanA::getWeapon() const
{
    return (this->_weapon.getType());
}

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << getWeapon() << std::endl;
}