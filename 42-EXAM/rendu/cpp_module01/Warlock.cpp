/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:08:03 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/05/28 15:58:19 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
    : _name(name), _title(title), _spellCount(0)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
    for (int i = 0; i < MAX_SPELLS; ++i)
        _spells[i] = NULL;
}

Warlock::~Warlock()
{
    for (int i = 0; i < _spellCount; ++i)
        delete _spells[i];
    std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
    return (this->_name);
}

const std::string& Warlock::getTitle() const
{
    return (this->_title);
}

void Warlock::setTitle(const std::string& title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if (!spell)
        return;
        
    for (int i = 0; i < _spellCount; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == spell->getName())
            return;
    }

    if (_spellCount < MAX_SPELLS)
    {
        _spells[_spellCount++] = spell->clone();
    }
    delete spell;
}

void Warlock::forgetSpell(const std::string& name)
{
    for (int i = 0; i < _spellCount; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == name)
        {
            delete _spells[i];

            for (int j = i; j < _spellCount - 1; ++j)
                _spells[j] = _spells[j + 1];

            _spells[_spellCount - 1] = NULL;
            --_spellCount;
            return;
        }
    }
}

void Warlock::launchSpell(const std::string& name, const ATarget& target) const
{
    for (int i = 0; i < _spellCount; ++i)
    {
        if (_spells[i] && _spells[i]->getName() == name)
        {
            _spells[i]->launch(target);
            return;
        }
    }
}