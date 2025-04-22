/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:07:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/20 13:22:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_ClapTrap"), FragTrap(), ScavTrap(), _name("Default_DiamondTrap")
{
    std::cout << "DiamondTrap: Default constructor called for DiamondTrap" << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name, const FragTrap& fragTrap, const ScavTrap& scavTrap)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    this->_hit = fragTrap.getHit();
    this->_energy = scavTrap.getEnergy();
    this->_attackDamage = fragTrap.getAttack();
    std::cout << "DiamondTrap: Constructor called for " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: Destructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap),  ScavTrap(diamondTrap)
{
    std::cout << "DiamondTrap: Copy constructor called for " << diamondTrap._name << std::endl;
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        ClapTrap::operator=(diamondTrap);
        this->_name = diamondTrap._name;
        this->_hit = diamondTrap._hit;
        this->_energy = diamondTrap._energy;
        this->_attackDamage = diamondTrap._attackDamage;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    if (_hit > 0)
    {
        std::cout << "Who am I? I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
    }
    else
    {
        std::cout << this->_name << " can't introduces himself! Because he's dead" << std::endl;
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &diamondTrap)
{
    out << "DiamondTrap (" << diamondTrap.getName() << ") - HP: " << diamondTrap.getHit()
        << ", Energy: " << diamondTrap.getEnergy() << ", Attack: " << diamondTrap.getAttack();
    return (out);
}
