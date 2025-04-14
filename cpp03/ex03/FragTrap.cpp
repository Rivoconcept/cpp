/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:36:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/14 18:40:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
    std::cout << "FragTrap: Default constructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    _hit = 100;
    _energy = 50;
    _attack = 20;
    std::cout << "FragTrap: Personalized constructor called for " << _name << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called for " <<  this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap()
{
    std::cout << "FragTrap: Copy constructor called for " << fragTrap._name << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap& fragTrap)
{
    if (this != &fragTrap)
    {
        this->_name = fragTrap._name;
        this->_hit = fragTrap._hit;
        this->_energy = fragTrap._energy;
        this->_attack = fragTrap._attack;
    }
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (_energy > 0 && _hit > 0)
    {
        std::cout << "FragTrap " <<  this->_name << " attacks " << target
                  << ", causing " <<  this->_attack << " points of damage!" << std::endl;
        this->_energy--;
    }
    else
    {
        std::cout << "FragTrap " <<  this->_name << " is out of energy or hit points and can't attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " says: High five, guys! ✋😄" << std::endl;
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &fragTrap)
{
    out << "FragTrap (" << fragTrap.getName() << ") - HP: " << fragTrap.getHit()
        << ", Energy: " << fragTrap.getEnergy() << ", Attack: " << fragTrap.getAttack();
    return (out);
}