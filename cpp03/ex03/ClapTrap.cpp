/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:25 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/20 11:17:18 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit(10), _energy(10), _attackDamage(0)
{
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit(10), _energy(10), _attackDamage(0)
{
    std::cout << "ClapTrap: Constructor called for " <<  this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called for " <<  this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap: Copy constructor called for " << clapTrap._name << std::endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this != &clapTrap)
    {
        this->_name = clapTrap._name;
        this->_hit = clapTrap._hit;
        this->_energy = clapTrap._energy;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return (*this);
}

const std::string& ClapTrap::getName() const
{
    return this->_name;
}

const unsigned int& ClapTrap::getHit() const
{
    return this->_hit;
}

const unsigned int& ClapTrap::getEnergy() const
{
    return this->_energy;
}

const unsigned int& ClapTrap::getAttack() const
{
    return this->_attackDamage;
}

void ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}

void ClapTrap::setHit(unsigned int hit)
{
    this->_hit = hit;
}

void ClapTrap::setEnergy(unsigned int energy)
{
    this->_energy = energy;
}

void ClapTrap::setAttack(unsigned int attack)
{
    this->_attackDamage = attack;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energy > 0 && _hit > 0)
    {
        std::cout << "ClapTrap " <<  this->_name << " attacks " << target
                  << ", causing " <<  this->_attackDamage << " points of damage!" << std::endl;
        this->_energy--;
    }
    else
    {
        std::cout << "ClapTrap " <<  this->_name << " is out of energy or hit points and can't attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit > 0)
    {
        _hit = (amount > _hit) ? 0 : (_hit - amount);
        std::cout << "ClapTrap " <<  this->_name << " takes " << amount
                  << " points of damage! Remaining hit points: " <<  this->_hit << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " <<  this->_name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energy > 0 && _hit > 0)
    {
        _hit += amount;
        _energy--;
        std::cout << "ClapTrap " <<  this->_name << " repairs itself, recovering " << amount
                  << " hit points! New hit points: " <<  this->_hit << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " <<  this->_name << " can't repair itself due to lack of energy or being destroyed!" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
    out << "ClapTrap (" << clapTrap.getName() << ") - HP: " << clapTrap.getHit()
        << ", Energy: " << clapTrap.getEnergy() << ", Attack: " << clapTrap.getAttack();
    return (out);
}