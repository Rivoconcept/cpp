/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:50:08 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:03:08 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

/*class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};*/

class ICharacter
{
public:
    // Destructeur virtuel : ESSENTIEL pour la même raison que dans AMateria.
    // Permet la suppression correcte d'objets Character via un pointeur ICharacter*.
    virtual ~ICharacter() {}

    // Fonctions virtuelles pures : définissent le contrat d'un personnage.
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;        // Équiper une Materia.
    virtual void unequip(int idx) = 0;          // Déséquiper une Materia à l'index idx.
    virtual void use(int idx, ICharacter& target) = 0; // Utiliser la Materia à l'index idx sur une cible.
};


#endif
