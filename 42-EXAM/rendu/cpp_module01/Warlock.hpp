/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:01:09 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/05/28 15:34:11 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        static const int MAX_SPELLS = 100;
        ASpell* _spells[MAX_SPELLS];
        int _spellCount;

    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& title);
        
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spell);
        void launchSpell(const std::string& spell, const ATarget& target) const;
        
};

#endif