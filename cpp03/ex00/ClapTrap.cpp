/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:25 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/02 13:57:24 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parameterized constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "Copy constructor called for " << clapTrap._name << std::endl;
    *this = clapTrap;
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

const std::string& ClapTrap::getName() const
{
    return this->_name;
}

const unsigned int& ClapTrap::getHitPoints() const
{
    return this->_hitPoints;
}

const unsigned int& ClapTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}

const unsigned int& ClapTrap::getAttackDamage() const
{
    return this->_attackDamage;
}

void ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy or hit points and can't attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        _hitPoints = (amount > _hitPoints) ? 0 : (_hitPoints - amount);
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount
                  << " hit points! New hit points: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " can't repair itself due to lack of energy or being destroyed!" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
    out << "ClapTrap [" << clapTrap.getName() << "] - HP: " << clapTrap.getHitPoints()
        << ", Energy: " << clapTrap.getEnergyPoints() << ", Attack: " << clapTrap.getAttackDamage();
    return out;
}