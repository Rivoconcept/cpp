/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:21 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::~HumanA() {}

std::string  HumanA::getName(void) const
{
    return (this->_name);
}

void HumanA::setName(std::string name)
{
   this->_name = name;
}

int  HumanA::getWeapon(void) const
{
    return (this->_weapon);
}

void HumanA::setWeapon(int weapon)
{
   this->_weapon = weapon;
}