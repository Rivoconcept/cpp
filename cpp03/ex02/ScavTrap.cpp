/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:36:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/20 11:17:18 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_Scav")
{
    std::cout << "ScavTrap: Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    _hit = 100;
    _energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap: Constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called for " <<  this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap()
{
    std::cout << "ScavTrap: Copy constructor called for " << scavTrap._name << std::endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        this->_name = scavTrap._name;
        this->_hit = scavTrap._hit;
        this->_energy = scavTrap._energy;
        this->_attackDamage = scavTrap._attackDamage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (_energy > 0 && _hit > 0)
    {
        std::cout << "ScavTrap " <<  this->_name << " attacks " << target
                  << ", causing " <<  this->_attackDamage << " points of damage!" << std::endl;
        this->_energy--;
    }
    else
    {
        std::cout << "ScavTrap " <<  this->_name << " is out of energy or hit points and can't attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (_hit > 0)
    {
        std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " can't enter gate guard mode! Because he's dead" << std::endl;
    }
}


std::ostream &operator<<(std::ostream &out, const ScavTrap &scavTrap)
{
    out << "ScavTrap (" << scavTrap.getName() << ") - HP: " << scavTrap.getHit()
        << ", Energy: " << scavTrap.getEnergy() << ", Attack: " << scavTrap.getAttack();
    return out;
}