/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:53 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/03 15:20:28 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
    std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
    std::cout << "Character: Constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = nullptr;
}

Character::Character(const Character& other)
{
    std::cout << "Character: Copy constructor called" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = nullptr;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
    std::cout << "Character: Destructor called" << std::endl;
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}

std::ostream& operator<<(std::ostream& out, const Character& character)
{
    out << "Character(" << character.getName() << ")" << std::endl;
    return (out);
}