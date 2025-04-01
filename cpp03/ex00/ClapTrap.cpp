/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:25 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/01 18:14:13 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clapTrap;
}

const std::string& ClapTrap::getName( void ) const
{
    return (this->_name);
}

const unsigned int& ClapTrap::getHitPoints( void ) const
{
    return (this->_hitPoints);
}

const unsigned int& ClapTrap::getEnergyPoints( void ) const
{
    return (this->_energyPoints);
}

const unsigned int& ClapTrap::getAttackPoints( void ) const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints( unsigned int energyPoints )
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackPoints( unsigned int attackDamage )
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "attack function called" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "takeDamage function called" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "beRepaired function called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this != &clapTrap)
    {
        this->_name = clapTrap._name;
        this->_hitPoints = clapTrap._hitPoints;
        this->_energyPoints = clapTrap._energyPoints;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
    out << clapTrap;
    return (out);
}