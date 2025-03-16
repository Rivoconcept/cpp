/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:39 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/16 12:59:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::~HumanB() {}

std::string  HumanB::getName(void) const
{
    return (this->_name);
}

void HumanB::setName(std::string name)
{
   this->_name = name;
}

int  HumanB::getWeapon(void) const
{
    return (this->_weapon);
}

void HumanB::setWeapon(int weapon)
{
   this->_weapon = weapon;
}

