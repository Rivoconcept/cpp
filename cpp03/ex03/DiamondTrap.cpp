/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:07:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/14 18:40:06 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_trap"), ScavTrap(), FragTrap(), _name("Default_Diamond")
{
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap: Default constructor called for DiamondTrap" << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: Destructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
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
        this->_attack = diamondTrap._attack;
    }
    return (*this);
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap: Personalized constructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Who am I? I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &diamondTrap)
{
    out << "DiamondTrap (" << diamondTrap.getName() << ") - HP: " << diamondTrap.getHit()
        << ", Energy: " << diamondTrap.getEnergy() << ", Attack: " << diamondTrap.getAttack();
    return (out);
}
